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
    // diff with private : protected members can be accessed by derived class in class def, 
    // not accesible direcly by derived obj but through a member function in derived class
    int prot = 2;

public:
    // public members of a class can be accessed from anywhere in the program
    // by other classes and functions
    int pub = 3;    

    int getPvt() {
        return pvt;
    }

    int getProt() {
        return prot;
    }

};

int main()
{
    Base bObj;

    cout  << "Base private member   : " << bObj.getPvt() << endl;
    cout  << "Base protected member : " << bObj.getProt() << endl;
    cout  << "Base public member    : " << bObj.pub << endl;
}
