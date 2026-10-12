// 10 | ADVANCED | Concurrency: threads, mutexes, atomics, async tasks, and promises
#include <atomic>
#include <chrono>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

// A counter protected by a mutex. std::lock_guard unlocks it automatically (RAII).
class SafeCounter {
public:
    void increment() {
        std::lock_guard<std::mutex> lock(mutex_);
        ++value_;
    }

    int value() {
        std::lock_guard<std::mutex> lock(mutex_);
        return value_;
    }

private:
    std::mutex mutex_;
    int value_ = 0;
};

long long sumRange(long long from, long long to) {
    long long total = 0;
    for (long long i = from; i <= to; ++i) {
        total += i;
    }
    return total;
}

int main() {
    // ---- 1. Threads with a mutex: protect shared data ---------------------------------------
    SafeCounter counter;
    std::vector<std::thread> threads;
    for (int t = 0; t < 4; ++t) {
        threads.emplace_back([&counter] {
            for (int i = 0; i < 10000; ++i) {
                counter.increment();
            }
        });
    }
    for (auto& th : threads) {
        th.join();                       // wait for each thread to finish
    }
    std::cout << "mutex counter = " << counter.value() << " (expected 40000)\n";

    // ---- 2. Atomics: lock-free updates for simple values ------------------------------------------
    std::atomic<int> hits{0};
    std::vector<std::thread> workers;
    for (int t = 0; t < 4; ++t) {
        workers.emplace_back([&hits] {
            for (int i = 0; i < 10000; ++i) {
                hits.fetch_add(1, std::memory_order_relaxed);
            }
        });
    }
    for (auto& w : workers) {
        w.join();
    }
    std::cout << "atomic hits = " << hits.load() << " (expected 40000)\n";

    // ---- 3. std::async: run work in the background and collect results with get() -------------------
    auto first = std::async(std::launch::async, sumRange, 1LL, 1000000LL);
    auto second = std::async(std::launch::async, sumRange, 1000001LL, 2000000LL);
    long long total = first.get() + second.get();   // get() waits for each result
    std::cout << "sum 1..2000000 = " << total << '\n';

    // ---- 4. promise and future: pass a value from one thread to another -------------------------------
    std::promise<std::string> promise;
    std::future<std::string> future = promise.get_future();

    std::thread producer([&promise] {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        promise.set_value("result from worker thread");
    });

    std::cout << future.get() << '\n';  // blocks until the value is set
    producer.join();

    return 0;
}
