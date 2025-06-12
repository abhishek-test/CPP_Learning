
// Suppose, the same function is defined in both the derived class and the base class.
// Now if we call this function using the object of the derived class, 
// the function of the derived class is executed -> Function over-riding

#include <iostream>
using namespace std;

class Base {
public:
    void print() {
        cout << "Base Function" << endl;
    }
};

class Derived : public Base {
public:
    void print() {
        cout << "Derived Function" << endl;
    }
};

int main() 
{
    Base bObj;
    Derived derived1, derived2;

    // respective print() functions invoked by respective class objects
    bObj.print(); // prints -> Base Function
    derived1.print(); // prints -> Derived Function

    // use derived class to access Base functions using :: operator
    derived1.Base::print(); // prints -> Base Function

    // use derived class to access Base functions using base class pointer
    // This is because even though ptr points to a Derived object, 
    // it is actually of Base type. So, it calls the member function of Base
    Base *ptr = &derived1;
    ptr->print();

    return 0;
}