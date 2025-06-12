// standard c++ namespace has wrappers written 
// over <mutex> : lock_guard(), unique_guard()

// lock guard
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

// std namespace mutex on scope basis, 
// remains alive as long as in scope, destroyed on end of scope
// need not call unlock() 
std::mutex mtx;  
int globalVal = 0;

void run(int threadId, int iter) {
    std::lock_guard<mutex> lock(mtx); // aquires mutex lock on mtx when lock() object is created
    for(int i=0; i<iter; i++) {
        globalVal++;
        cout << "Thread Id " << threadId << endl; 
    }
} // as the scope ends the lock on mtx is removed 

int main()
{
    std::thread t1(run, 1, 10);
    std::thread t2(run, 2, 10);

    if(t1.joinable())
        t1.join();

    if(t2.joinable())
        t2.join();

    cout << " Val : " << globalVal << endl;
}