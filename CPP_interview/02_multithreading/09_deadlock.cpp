#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex m1;
std::mutex m2;

// CPU is so fast that m1 gets locked and m2 also get locked 
// before other thread requests for lock
// hence thread1/thread2 gets executed completely before other
// without deadlock

// what happens when a delay/sleep is introduced ? -> deadlock
// since both are waiting on thread1 and thread2 mutexes

// what if order of mutex lock is changed in either ??
// deadlock is resolved

void thread1() {
    m1.lock();
    std::this_thread::sleep_for(chrono::seconds(1));
    m2.lock();
    cout << "Critical section of thread one" << endl;
    m1.unlock();
    m2.unlock();
}

void thread2() {
    m2.lock();
    std::this_thread::sleep_for(chrono::seconds(1));
    m1.lock();
    cout << "Critical section of thread two" << endl;
    m2.unlock();
    m1.unlock();
}

int main()
{
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();
}