
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    // array - fixed size in modern C++
    std::array<int, 5> myArr; // = {3,5,1,2,4};
    myArr.fill(10);
    std::sort(myArr.begin(), myArr.end());
    
    for (int x : myArr)
        cout << x << " ";
    cout << std::endl;

    // normal pointer and dynamic mem allocation
    int count = 10;

    unsigned char *ptrM = (unsigned char*)malloc(count*sizeof(unsigned char));  // garbage
    unsigned char *ptrC = (unsigned char*)calloc(count, sizeof(unsigned char)); // 0
    int *ptrN = new int[count];  // stores garbage, use[] for chunk of memory

    // sets each byte to 55 not each int, give garbage values
    memset(ptrC, 55, count*sizeof(unsigned char)); 

    // or set to a fixed value
    fill(ptrN, ptrN + count, 149);

    // access each element
    for (size_t i = 0; i < count; i++) {
        cout << *(ptrC + i) << endl;      // use ptrM, ptrC or ptrN
    }   

    free(ptrM);
    free(ptrC);    // delete(ptrC) can also be used 
    delete[] ptrN; // use delete[] for chunk of blocks else use delete

    // pointer arithmetic
    int arr[] = {10, 20, 30};
    int* ptr = arr;

    // Dereference the current pointer, then increment the pointer
    cout << *ptr++ << endl;  // Outputs 10, ptr now at arr[1]

    // Increment the pointer first, then dereference
    cout << *++ptr << endl;  // ptr moves to arr[2], outputs 30

}