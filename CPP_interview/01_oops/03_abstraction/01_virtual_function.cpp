#include <iostream>

using namespace std;

// if we create a pointer of Base type to point to an object of Derived class
// and call the print() function, it calls the print() function of the Base class
// i.e. the member function of Base is not overridden
// to solve this use 'virtual' function

class Base {
public:
    virtual void print() {
        cout << "Base class print" << endl;
    }    
};

class Derived : public Base {
public:
    // over ride specifies the member functions of the derived 
    // classes that override the member function of the base class
    // 'override' is optional but enables compile-time checking
    void print() override {  
        cout << "Derived class print" << endl;
    }
};


int main()
{
    Derived dObj;
    Base *ptr = &dObj;

    ptr->print();

}

