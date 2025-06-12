
#include <iostream>
#include <string>
using namespace std;

// make getType() virtual in the Animal class, then  

class Animal {
   private:
    string type;

   public:
    // constructor to initialize type
    Animal() {
        type = "Animal";
    }

    // declare virtual function
    virtual string getType() {
        return type;
    }
};

class Dog : public Animal {
   private:
    string type;

   public:
    // constructor to initialize type
    Dog() {
        type = "Dog";
    }

    string getType() override {
        return type;
    }
};

class Cat : public Animal {
   private:
    string type;

   public:
    // constructor to initialize type
    Cat() {
        type = "Cat";
    }

    string getType() override {
        return type;
    }
};

// create a single, separate print() function that accepts a pointer of 
// Animal (Base) type as its argument
// functions is made static to keep visibility to this file
static void print(Animal* ani) {
    // use this single function to override the virtual function
    cout << "Animal: " << ani->getType() << endl;
}

int main() {
    // created 3 Animal pointers to dynamically create objects of
    // Animal, Dog and Cat classes
    Animal* animal1 = new Animal();
    Animal* dog1 = new Dog();
    Animal* cat1 = new Cat();

    // use 
    print(animal1);
    print(dog1);
    print(cat1);
}