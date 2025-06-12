/*
1. shared_ptr is a smart pointer which can share the ownership of managed object
2. Several shared_ptr can point to same managed object
3. It keeps a reference count to maintain how many shared_ptr is pointing to same object.
   Once last shared_ptr goes out of scope, managed object gets deleted
4. shared_ptr is CB (ref count) is thread safe, managed object is not (class object)
5. Three ways shared-ptr destroys the managed object:
    (a) if last shared_ptr goes out of scope
    (b) if we initialize shared_ptr with some other shared_ptr
    (c) if we reset shared_ptr
6. Ref count doesn't work when we use reference or pointer of shared_ptr (it has to be copy value only, ref will not work)

    |----------------------|
    |    |-----|  |-----|  |
SP->|    | MB  |  | CB  |--|--> control block (ref count) is thread safe  
    |    |-----|  |-----|  |
    |-------|--------------|
            |
            |
            v
    managed block (class object) is not thread safe   

*/

#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

using namespace std;

class Foo {
    int x;
public:
    Foo(int x):x{x} {}
    int getX() {return x; }
    ~Foo() { cout << "~Foo()" << endl; }
};


void fun(std::shared_ptr<Foo> sp, int count) {
    static std::mutex m1;
    std::lock_guard<std::mutex> loc(m1);
    cout << "thread: " << count << sp.use_count() << endl;
}

int main()
{
    // memory leak, forgot: delete f;
    //Foo *f = new Foo(10);
    //cout << f->getX() << endl;

    std::shared_ptr<Foo> sp(new Foo(10));
    cout << sp->getX() << endl;
    cout << sp.use_count() << endl;

    std::shared_ptr<Foo> sp1 = sp;    // &sp1 =sp or *sp1=&sp does not give same ref count Point (6) above
    cout << sp.use_count() << endl;
    cout << sp1.use_count() << endl;

    // destructor is called only once

    // example of thread safe CB -> run separately
    std::shared_ptr<Foo> sp(new Foo(10));
    cout << "main before: " << sp.use_count() << endl;
    thread t1(fun,sp,1), t2(fun,sp,2), t3(fun,sp,3);

    t1.join(); t2.join(); t3.join();

    return 0;

 }







