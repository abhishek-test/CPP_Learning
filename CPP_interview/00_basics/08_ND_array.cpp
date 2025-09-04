#include <stdlib.h>
#include <memory>
#include <array>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/* Dynamic memory allocation */

int main()
{
    /*--------------------- 1D dynamic array -----------------*/
    int size = 100;
    int *ptr = new int[size];
    std::fill(ptr, ptr+size, 23);

    for (size_t i=0; i<size; ++i) {
        cout << ptr[i] << " ";
    }
    cout << endl;

    /*------------------ 2D array - can be implemented in 3 ways ------------------*/

    /* 1. In a single memory block  */
    size_t rows = 3;
    size_t cols = 4;

    int *ptr_2D_single_block = new int[rows * cols];
    for (size_t i=0; i< rows; ++i) {
        for (size_t j=0; j< cols; ++j)
            ptr_2D_single_block[i*cols + j] =  3; // accessing elements at [i][j]
    }
    delete[] ptr_2D_single_block;

    /* 2. Use double pointer (pointer to pointer) - low level memory control and performance critical */
    int** arr = new int*[rows];
    for(size_t i=0; i<rows; ++i) {
        arr[i] = new int[cols];  // allocate memory for each row
    }

    arr[1][3] = 50; // accessing 

    // clean up
    for(size_t i=0; i<rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    /* 3. Using vectors - modern c++ : manages memory and is safe */
    vector<vector<int>> arr_vec(rows, vector<int>(cols));
    for (auto &row : arr_vec) {  // use & for reference so changes reflect
        fill(row.begin(), row.end(), 20);
    }
    
    cout << arr_vec[2][2];  // access

    /*--------------------------- 3D array -----------------------------------*/

    /* 1. In a single memory block */
    size_t depth = 5;
    int *ptr_3D_single_block = new int[rows*cols*depth];
    int d =2, r = 2, c = 2;
    ptr_3D_single_block[d*(rows*cols) + (r*cols + c)] = 20; // access
    delete[] ptr_3D_single_block;

    /* 2. Use triple pointers */
    int*** arr_3d = new int**[depth];

    for (int i = 0; i < depth; ++i) {
        arr_3d[i] = new int*[rows];
        for (int j = 0; j < rows; ++j) {
            arr_3d[i][j] = new int[cols];
        }
    }

    arr_3d[0][1][2] = 10;  // access

    // Cleanup
    for (int i = 0; i < depth; ++i) {
        for (int j = 0; j < rows; ++j) {
            delete[] arr_3d[i][j];
        }
        delete[] arr_3d[i];
    }
    
    delete[] arr_3d;

}
