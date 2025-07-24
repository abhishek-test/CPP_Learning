#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int globalVal = 0;
std::mutex m;

// // using standard lock
// void increment() {
//     m.lock();  // blocking function
//     ++globalVal;
//     m.unlock();    
// }

// using try_lock: returns true if lock is aquired else false
// returns different result everytime since different threads 
// may not be able to get the lock everytime so increment is not done
void increment() {
    for(int i=0; i<100000; i++) {   
        if(m.try_lock()) { // ->result is not fixed as threads wait is conditional
            //m.lock(); -> result is fixed: as thread wait for other to finish
            ++globalVal;
            m.unlock();
        }
    }
}

int main()
{
    cout << "Value before : " << globalVal << endl;

    // both threads try to change globalVal at same time
    // race condition -> when multiple threads try to change value of same resource
    // 'changing' is must not just accessing/reading
    // code changing the resource value is 'critical section'
    // mutex locks are put on criticla section
    // there is always some diff in time when thread request reaches CPU
    // thread reaching fist gets the lock first and so on
    std::thread t1(increment);
    std::thread t2(increment);

    if(t1.joinable())
        t1.join();

    if(t2.joinable())
        t2.join();

    cout << "Value after : " << globalVal << endl;
}