/// @brief adder is a simple proxy that will delegate work to
///        the scheduler.
class adder
{
public:
  adder(high_priority_scheduler& scheduler)
    : scheduler_(scheduler)
  {}

  /// @brief Add a and b with a priority.
  ///
  /// @return Return future result.
  template <typename T>
  boost::unique_future<T> add(
    high_priority_scheduler::priority_type priority,
    const T& a, const T& b)
  {
    // Insert method request
    return scheduler_.insert(
      priority,
      boost::bind(&adder::do_add<T>, a, b));
  }

  /// @brief Add a and b.
  ///
  /// @return Return future result.
  template <typename T>
  boost::unique_future<T> add(const T& a, const T& b)
  {
    return add(high_priority_scheduler::priority_type(), a, b);
  }

private:

  /// @brief Actual add a and b.
  template <typename T>
  static T do_add(const T& a, const T& b)
  {
    std::cout << "Starting addition of '" << a 
              << "' and '" << b << "'" << std::endl;
    // Mimic busy work.
    boost::this_thread::sleep_for(boost::chrono::seconds(2));
    std::cout << "Finished addition" << std::endl;
    return a + b;
  }

private:
  high_priority_scheduler& scheduler_;
};

