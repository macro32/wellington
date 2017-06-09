// Standard includes
#include <algorithm> // std::find_if
#include <iostream>
#include <string>

// 3rd party includes
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/make_shared.hpp>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/utility/result_of.hpp>

/// @brief scheduler that provides limits with prioritized jobs.
template <typename Priority,
          typename Compare = std::less<Priority> >
class scheduler
{
public:
  typedef Priority priority_type;
private:

  /// @brief method_request is used to couple the guard and call
  ///        functions for a given method.
  struct method_request
  {
    typedef boost::function<bool()> ready_func_type;
    typedef boost::function<void()> run_func_type;

    template <typename ReadyFunctor,
              typename RunFunctor>
    method_request(ReadyFunctor ready,
                   RunFunctor run)
      : ready(ready),
        run(run)
    {}

    ready_func_type ready;
    run_func_type run;
  };

  /// @brief Pair type used to associate a request with its priority.
  typedef std::pair<priority_type,
                    boost::shared_ptr<method_request> > pair_type;

  static bool is_method_ready(const pair_type& pair)
  {
    return pair.second->ready();
  }

public:

  /// @brief Construct scheduler.
  ///
  /// @param max_threads Maximum amount of concurrent task.
  /// @param max_request Maximum amount of request.  
  scheduler(std::size_t max_threads,
            std::size_t max_request)
    : work_(io_service_),
      max_request_(max_request),
      request_count_(0)
  {
    // Spawn threads, dedicating them to the io_service.
    for (std::size_t i = 0; i < max_threads; ++i)
      threads_.create_thread(
        boost::bind(&boost::asio::io_service::run, &io_service_));
  }

  /// @brief Destructor.
  ~scheduler()
  {
    // Release threads from the io_service.
    io_service_.stop();
    // Cleanup.
    threads_.join_all();
  }

  /// @brief Insert a method request into the scheduler.
  ///
  /// @param priority Priority of job.
  /// @param ready_func Invoked to check if method is ready to run.
  /// @param run_func Invoked when ready to run.
  ///
  /// @return future associated with the method.
  template <typename ReadyFunctor,
            typename RunFunctor>
  boost::unique_future<typename boost::result_of<RunFunctor()>::type>
  insert(priority_type priority, 
         const ReadyFunctor& ready_func,
         const RunFunctor& run_func)
  {
    typedef typename boost::result_of<RunFunctor()>::type result_type;
    typedef boost::unique_future<result_type> future_type;

    boost::unique_lock<mutex_type> lock(mutex_);

    // If max request has been reached, then return an invalid future.
    if (max_request_ &&
        (request_count_ == max_request_))
      return future_type();

    ++request_count_;

    // Use a packaged task to handle populating promise and future.
    typedef boost::packaged_task<result_type> task_type;

    // Bind does not work with rvalue, and packaged_task is only moveable,
    // so allocate a shared pointer.
    boost::shared_ptr<task_type> task = 
      boost::make_shared<task_type>(run_func);

    // Create method request.
    boost::shared_ptr<method_request> request =
      boost::make_shared<method_request>(
        ready_func,
        boost::bind(&task_type::operator(), task));

    // Insert into priority.  Hint to inserting as close to the end as
    // possible to preserve insertion order for request with same priority.
    activation_list_.insert(activation_list_.end(),
                            pair_type(priority, request));

    // There is now an outstanding request, so post to dispatch.
    io_service_.post(boost::bind(&scheduler::dispatch, this));

    return task->get_future();
  }

  /// @brief Insert a method request into the scheduler.
  ///
  /// @param ready_func Invoked to check if method is ready to run.
  /// @param run_func Invoked when ready to run.
  ///
  /// @return future associated with the method.
  template <typename ReadyFunctor,
            typename RunFunctor>
  boost::unique_future<typename boost::result_of<RunFunctor()>::type>
  insert(const ReadyFunctor& ready_func,
         const RunFunctor& run_func)
  {
    return insert(priority_type(), ready_func, run_func);
  }

  /// @brief Insert a method request into the scheduler.
  ///
  /// @param priority Priority of job.
  /// @param run_func Invoked when ready to run.
  ///
  /// @return future associated with the method.
  template <typename RunFunctor>
  boost::unique_future<typename boost::result_of<RunFunctor()>::type>
  insert(priority_type priority, 
         const RunFunctor& run_func)
  {
    return insert(priority, &always_ready, run_func);
  }

  /// @brief Insert a method request with default priority into the
  ///        scheduler.
  ///
  /// @param run_func Invoked when ready to run.
  ///
  /// @param functor Job to run.
  ///
  /// @return future associated with the job.
  template <typename RunFunc>
  boost::unique_future<typename boost::result_of<RunFunc()>::type>
  insert(const RunFunc& run_func)
  {
    return insert(&always_ready, run_func);
  }

  /// @brief Cancel all outstanding request.
  void cancel()
  {
    boost::unique_lock<mutex_type> lock(mutex_);
    activation_list_.clear();
    request_count_ = 0;
  } 

private:

  /// @brief Dispatch a request.
  void dispatch()
  {
    // Get the current highest priority request ready to run from the queue.
    boost::unique_lock<mutex_type> lock(mutex_);
    if (activation_list_.empty()) return;

    // Find the highest priority method ready to run.
    typedef typename activation_list_type::iterator iterator;
    iterator end = activation_list_.end();
    iterator result = std::find_if(
      activation_list_.begin(), end, &is_method_ready);

    // If no methods are ready, then post into dispatch, as the
    // method may have become ready.
    if (end == result)
    {
      io_service_.post(boost::bind(&scheduler::dispatch, this));
      return;
    }

    // Take ownership of request.
    boost::shared_ptr<method_request> method = result->second;
    activation_list_.erase(result);

    // Run method without mutex.
    lock.unlock();
    method->run();    
    lock.lock();

    // Perform bookkeeping.
    --request_count_;
  }

  static bool always_ready() { return true; }

private:

  /// @brief List of outstanding request.
  typedef boost::multi_index_container<
    pair_type,
    boost::multi_index::indexed_by<
      boost::multi_index::ordered_non_unique<
        boost::multi_index::member<pair_type,
                                   typename pair_type::first_type,
                                   &pair_type::first>,
        Compare
      >
    >
  > activation_list_type;
  activation_list_type activation_list_;

  /// @brief Thread group managing threads servicing pool.
  boost::thread_group threads_;

  /// @brief io_service used to function as a thread pool.
  boost::asio::io_service io_service_;

  /// @brief Work is used to keep threads servicing io_service.
  boost::asio::io_service::work work_;

  /// @brief Maximum amount of request.
  const std::size_t max_request_;

  /// @brief Count of outstanding request.
  std::size_t request_count_;

  /// @brief Synchronize access to the activation list.
  typedef boost::mutex mutex_type;
  mutex_type mutex_;
};

typedef scheduler<unsigned int, 
                  std::greater<unsigned int> > high_priority_scheduler;

