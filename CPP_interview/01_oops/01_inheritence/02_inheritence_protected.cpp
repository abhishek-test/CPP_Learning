#include <iostream>

using namespace std;

class Base {

private:
    // not allowed to be accessed directly by any object or function outside the class
    // only the member functions or the friend functions are allowed to access
    int pvt=1;

protected:
    // not allowed to be accessed directly by any object or function outside the class
    // only the member functions or the friend functions are allowed to access
    // diff with private : protected members can be accessed by derived class as well
    int prot = 2;

public:
    // public members of a class can be accessed from anywhere in the program
    // by other classes and functions
    int pub = 3;    

    int getPvt() {
        return pvt;
    }

};

class Derived : protected Base {

public:
    // derived class has access to protected and public member of base class
    int getProt() {
        return prot;
    }

    int getPub() {
        return pub;
    }

};

int main()
{
    Derived dObj;

    cout  << "Derived private member   : " << "NA" << endl;
    cout  << "Derived protected member : " << dObj.getProt() << endl;
    cout  << "Derived public member    : " << dObj.getPub() << endl;
}
