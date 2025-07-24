
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;
ull oddSum = 0;
ull evenSum = 0;

void sumOdd(ull start, ull end) {
    for(ull i=start; i<=end; ++i) {
        if(i & 1 == 1) {
            oddSum += 1;
        }
    }
}

void sumEven(ull start, ull end) {
    for(ull i=start; i<=end; ++i) {
        if(i & 1 == 0) {
            evenSum += 1; 
        }
    }
}

int main() // main thread is created
{
    ull start =0, end = 1900000000;

    auto startTime = high_resolution_clock::now();

    // create threads using function pointers
    // order of thread creation is done by OS and not 
    // known in advance, so we don't know which is 
    // created first 
    thread t1(sumOdd, start, end);
    thread t2(sumEven, start, end);

    // wait until threads join back the main thread
    t1.join();
    t2.join();  

    /*
    sumOdd(start, end);
    sumEven(start, end);
    */

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);

    cout << " Duration (ms) : " << duration.count() << endl;
}