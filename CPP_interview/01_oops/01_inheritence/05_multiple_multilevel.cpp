// multilevel, multiple inheritence

#include <iostream>
using namespace std;

// classes for multilevel inheritence
class A {
    public:
      void display() {
          cout<<"Base class content" << endl;
      }
};

class B : public A {};

class C : public B {};

// classes for multiple inheritence
class Mammal {
  public:
    Mammal() {
      cout << "Mammals can give direct birth" << endl;
    }

    void print() {
        cout << "Mammal class print" << endl;
    }
};

class WingedAnimal {
  public:
    WingedAnimal() {
      cout << "Winged animal can flap" << endl;
    }

    void print() {
        cout << "WingedAnimal class print" << endl;
    }
};

class Bat: public Mammal, public WingedAnimal {}; // <- multiple inheritence 


int main() {

    // multi level inheritence :
    // member functions and destructors are called from derived -> base
    // function is linearly searched up in the inheritance hierarchy until a matching function is found
    // constructors are called from base -> derived
    C obj;
    obj.display();

    // multiple inheritence :
    // constructors are called in order of inheritence
    Bat b1;
    //b1.print();  // -> ambigous
    b1.WingedAnimal::print(); // -> solve ambiguity usin :: 
}