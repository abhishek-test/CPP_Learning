#include <iostream>
#include <memory>  // need to be included

using namespace std;

class MyClass {
private:
    int x;
public:
    MyClass (int xx) { x = xx; }
    int getX() { return x; }
    ~MyClass() { cout << "Destructor called " << endl; }
};

int main()
{
    // obj is on heap and not on stack, when it goes out of scope
    // it is not destroyed if delete is not called
    // The destructor on a heap object is not called until you free the object.
    // hence destructor is not called -> memory leak
    MyClass *obj = new MyClass(10);    
    cout << obj->getX() << endl;

    /****************************************************************/

    // p is not dynamic and created on stack
    // hence destructor is called -> no memory leak
    // unique pointer is light wrapper around MyClass()

    // not exception safe : if exception occurs pointer is not deleted
    std::unique_ptr<MyClass> p1(new MyClass(20));   

    // exception safe : if exception occurs pointer is deleted
    std::unique_ptr<MyClass> p2 = make_unique<MyClass>(20); 

    // p1 = p2 : FAILS as unique pointer cant be copied
    unique_ptr<MyClass> p3 = std::move(p2); // PASS : ownership has moved from p2 to p3, p2 is nullptr

    cout << p3->getX() << endl;

    MyClass *p4 = p3.release();  // returns pointer to object and release ownership from p3 which is nullptr now

    // ******************** unique pointer with array of ints ****************************
    const size_t size = 5;
    std::unique_ptr<int[]> arr = std::make_unique<int[]>(size);

    // set each leement one by one 
    for (size_t i = 0; i < size; ++i) {
        arr[i] = static_cast<int>(i * 10);
    }

    // or Set all elements to 42 at once
    std::fill(arr.get(), arr.get() + size, 42);

    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";  // Output: 42 42 42 42 42
    }

}