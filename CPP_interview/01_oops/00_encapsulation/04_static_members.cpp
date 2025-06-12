#include <iostream>

using namespace std;

class Box {

private:
    double length;
    double breadth;
    double height;

public:
    // no matter how many objects are created, there is only one copy 
    // of static member shared by all objects
    // It is initialized to zero when first obj is crated if no other 
    // initialization is present
    // cant be initialized in class definition but initialized 
    // outside the class using :: operator with class name
    // do not contribute to size of class obj
    static int objectCount;

    Box (double l=2.0, double b=2.0, double h=2.0) {
        cout << "Constructor called " << endl;
        length = l;
        breadth = b;
        height = h;

        objectCount++;
    }

    double volume() {
        return (length * breadth * height);
    }

    // independent of any object of the class
    // can be called even if no object exists
    // accessed using only class name and :: [eg. Box::getCount()]

    // it can access static data member, other static functions
    // and any other function from outside the class
    // do not have access to this pointer
    // used to check if class objects are created or not
    static int getCount() {
        return objectCount;
    }
};

int Box::objectCount = 0;

int main()
{
    cout << "Initial count : " << Box::getCount() << endl;

    Box b1(3.3, 2.2, 1.1);
    Box b2(3.5, 2.5, 1.5);

    cout << "Final count : " << Box::getCount() << endl;
}