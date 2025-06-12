
// There are 3 launch policies for creating tasks
// 1. std::launch::async
// 2. std::launch::deffered
// 3. std::launch::async | std::launch::deffered

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <future>

using namespace std;
using namespace std::chrono;

typedef long int ull;

ull findOdd(ull start, ull end) {
    ull OddSum = 0;
    for(ull i=start; i<=end; ++i) {
        if(i & 1) {
            OddSum += i;
        }
    }    
    return OddSum;
}

int main()
{
    ull start = 0, end = 1900000000;

    // possible to return value with async

    cout << "Thread created if policy is std::launch::async!!" << endl;
    //std::future<ull> OddSum = std::async(std::launch::deferred, findOdd, start, end);
    std::future<ull> OddSum = std::async(std::launch::async, findOdd, start, end);

    cout << "Waiting For Results!!" << endl;

    // OddSum is a blocking call for defered launch and non blocking for async
    cout << "OddSum: " << OddSum.get() << endl;  

    cout << "Completed !! " << endl;
}