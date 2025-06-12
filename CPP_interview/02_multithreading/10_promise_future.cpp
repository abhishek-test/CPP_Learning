
// used when we need value of a variable running in thread in main (calling thread)
// 

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <future>

using namespace std;
using namespace std::chrono;
typedef unsigned long int ull;


// assume this op takes 3 seconds
void findOdd(std::promise<ull>&& OddSumPromise, ull start, ull end) {
    ull OddSum = 0;
    for(ull i=start; i<=end; ++i) {
        if(i & 1) {
            OddSum += i;
        }
    }
    OddSumPromise.set_value(OddSum);
}

int main()
{
    ull start=0, end=1900000000;

    std::promise<ull> OddSum;
    std::future<ull> OddFuture = OddSum.get_future();

    std::thread t1(findOdd, std::move(OddSum), start, end);

    cout << "Waiting for result" << endl;  

    // if we have some operation taking 5 seconds
    // whole op will take 5s as we would get OddFuture in 3sec
    // if future is not used, both ops will take 8s in total
    // this is parallelism which saves time

    cout << "Odd Sum: " << OddFuture.get() << endl;

    cout << "Completed ! " << endl;

    t1.join();
}