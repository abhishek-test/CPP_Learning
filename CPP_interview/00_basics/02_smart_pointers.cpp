// 1. wrapper around pointer to manage lifetime
// 2. remove chances of memory leaks
// 3. make sure obj is deleted if is is not referenced anymore

#include <iostream>
#include <cstdlib>

using namespace std;

// can be written as template so
// all data types can be handled
class MyInt {
private:
    int *data;
public:
    MyInt(int *p = nullptr) { data = p; }
    ~MyInt() { delete data;  }
    int& operator *() {  return *data;  }
};

//template <typename T>
//class MyInt {
//private:
//    T *data;
//public:
//    MyInt(T *p = nullptr) { data = p; }
//    ~MyInt() { delete data; }
//    T& operator *() { return *data; }
//};


int main()
{
    int *p = new int(3.1425);  // typecasted to int
    MyInt obj = MyInt(p);  // wrapper around pointer p   
    // use auto above instead of MyInt when using template as type is not determined

    cout << *obj << endl;

    // delete p is not required since deletion is handled 
    // when it goes out of scope and destructor is called;
    // there delete p is present
}