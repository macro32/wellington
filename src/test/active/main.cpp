#include "scheduler.hpp"
#include "adder.hpp"

bool get(bool& value) { return value; }
void guarded_call()
{
  std::cout << "guarded_call" << std::endl; 
}

int main()
{
  const unsigned int max_threads = 1;
  const unsigned int max_request = 4;

  // Sscheduler
  high_priority_scheduler scheduler(max_threads, max_request);

  // Proxy
  adder adder(scheduler);

  // Client

  // Add guarded method to scheduler.
  bool ready = false;
  std::cout << "Add guarded method." << std::endl;
  boost::unique_future<void> future1 = scheduler.insert(
    boost::bind(&get, boost::ref(ready)),
    &guarded_call);

  // Add 1 + 100 with default priority.
  boost::unique_future<int> future2 = adder.add(1, 100);

  // Force sleep to try to get scheduler to run request 2 first.
  boost::this_thread::sleep_for(boost::chrono::seconds(1));

  // Add:
  //   2 + 200 with low priority (5)
  //   "test" + "this" with high priority (99)
  boost::unique_future<int> future3 = adder.add(5, 2, 200);
  boost::unique_future<std::string> future4 = adder.add(99,
    std::string("test"), std::string("this"));

  // Max request should have been reached, so add another.
  boost::unique_future<int> future5 = adder.add(3, 300);

  // Check if request was added.
  std::cout << "future1 is valid: " << future1.valid()
          << "\nfuture2 is valid: " << future2.valid()
          << "\nfuture3 is valid: " << future3.valid()
          << "\nfuture4 is valid: " << future4.valid()
          << "\nfuture5 is valid: " << future5.valid()
          << std::endl;

  // Get results for future2 and future3.  Do nothing with future4's results.
  std::cout << "future2 result: " << future2.get()
          << "\nfuture3 result: " << future3.get()
          << std::endl;

  std::cout << "Unguarding method." << std::endl;
  ready = true;
  future1.wait();
}
