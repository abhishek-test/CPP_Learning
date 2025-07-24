#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    // vector is a sequence container -> contigously stored in memory
    // dynamic : grows dynamically as linked list
    // random access : as in array with O(1) complexity

    vector<int> myVector;
    int count = 1900000;
    
    // reserve a ballpark buffer
    // if not: for every push_back previous buffer is destroyed and a new buffer is created
    // (and elements are copied which is time consuming) with size twice as previous buffer which consumes time
    myVector.reserve(count); 

    auto startTime = high_resolution_clock::now();

    for(int i=0; i<count; i++) {
        myVector.push_back(i);
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);

    cout << "Time taken: " << duration.count() << endl;

}