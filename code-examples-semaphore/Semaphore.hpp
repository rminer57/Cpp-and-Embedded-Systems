
#include <atomic>

class Semaphore
{

public:
    Semaphore() :
        count_(0) // Initialized as locked.
    {

    }
    inline void notify() {
        count_++;
    }

    void wait() {
        while(!try_wait()) {
            //Spin Locking
        }
    }

    bool try_wait() {
        int count = count_;
        if(count) {
            return count_.compare_exchange_strong(count, count - 1);
        } else {
            return false;
        }
    }
	
private:
    std::atomic<int> count_;	
};


// EXAMPLE USAGE
#if 0

#include <iostream>
#include "Semaphore.hpp"
#include <thread>
#include <vector>

Semaphore sem;
int counter;

void run(int threadIdx) {
    while(!sem.try_wait()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    //Alternative use wait
    //sem.wait()
    std::cout << "Thread " << threadIdx << " enter critical section" << std::endl;
    counter++;
    std::cout << "Thread " << threadIdx << " incresed counter to " << counter << std::endl;

    // Do work;
    std::this_thread::sleep_for(std::chrono::milliseconds(30));

    std::cout << "Thread " << threadIdx << " leave critical section" << std::endl;
    sem.notify();
}
int main() {
    std::vector<std::thread> threads;
    for(int i = 0; i < 15; i++) {
        threads.push_back(std::thread(run, i));
    }

    sem.notify();


    for(auto& t : threads) {
        t.join();
    }
    std::cout << "Terminate main." << std::endl;
    return 0;
}

#endif