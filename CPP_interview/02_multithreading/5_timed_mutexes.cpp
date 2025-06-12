
// wait for mutex lock in two ways:
// 1. wait for 'n' seconds
// 2. wait until 'n' seconds from now 

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::timed_mutex mtx;
int globalVal = 0;

// wait for n seconds
void increment(int i) {

    auto now = std::chrono::steady_clock::now();
    if(mtx.try_lock_until(now + std::chrono::seconds(3))) {
    //if(mtx.try_lock_for(std::chrono::seconds(3))) {   // wait for n sec, change seconds values and check 
        cout << "Thrad " << i << " got the lock " << endl;
        ++globalVal;
        std::this_thread::sleep_for(chrono::seconds(2));  // change second values and check
        mtx.unlock();
    }
    else {
        cout << "Thread " << i << " could not enter " << endl;
    }
}

int main()
{
    std::thread t1(increment, 1);
    std::thread t2(increment, 2);

    if(t1.joinable())
        t1.join();

    if(t2.joinable())
        t2.join();

    cout << "Val : " << globalVal << endl;
}