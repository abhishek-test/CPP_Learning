
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

using namespace std;

int main()
{
    // normal pointer and dynamic mem allocation
    int count = 10;

    unsigned char *ptrM = (unsigned char*)malloc(count*sizeof(unsigned char));  // garbage
    unsigned char *ptrC = (unsigned char*)calloc(count, sizeof(unsigned char)); // 0
    int *ptrN = new int[count];  // stores garbage, use[] for chunk of memory

    // setting memory
    memset(ptrC, 55, count*sizeof(unsigned char));  // use ptrM, ptrC or ptrN only for zero init

    // or set to a fixed value
    fill(ptrN, ptrN + count, 149);

    // access each element
    for (size_t i = 0; i < count; i++) {
        cout << *(ptrC + i) << endl;      // use ptrM, ptrC or ptrN
    }   

    free(ptrM);
    free(ptrC); // delete(ptrC) can also be used 
    delete[] ptrN; // use delete[] for chunk of blocks else use delete
}