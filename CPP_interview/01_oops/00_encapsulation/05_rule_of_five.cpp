#include <iostream>
#include <utility> // for using move
using namespace std;

// Rule of Five: If a class manages resources (like dynamic memory), 
// it should define all five special member functions: destructor, copy constructor, 
// copy assignment operator, move constructor, and move assignment operator. 
// This ensures proper resource management and avoids issues like double deletion or memory leaks.

// if there is no resource management, then we can rely on compiler generated special member functions
// Rule of Zero comes in, which states that if a class does not manage resources, 
// it should not define any of the special member functions,
// and instead rely on the compiler-generated versions. This leads to simpler and more maintainable code

class ResourceManager {
private:
    int* data;
    size_t size;

public:
    // default constructor
    ResourceManager(size_t sz = 0)
        : data(new int[sz])
        , size(sz)
    {}

    // Destructor
    ~ResourceManager() { delete[] data; }

    // Copy Constructor - create new object using existing one
    // Deep copy - both hold individual copies of data, point to different memory
    ResourceManager(const ResourceManager& other)
        : data(new int[other.size])
        , size(other.size)
    { copy(other.data, other.data + other.size, data); }

    // Copy Assignment Operator - copies data from one to another (both existing already - of diff size ??)
    // Deep copy - both hold individual copies of data, point to different memory
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            delete[] data;
            data = new int[other.size];
            size = other.size;
            copy(other.data, other.data + other.size, data);
        }
        return *this;
    }

    // Move Constructor - new obj points to other's resources, other is set to null
    // new obj owns the memory, other is left in valid but empty state
    // move - just transfer of resource (not a shallow copy)
    ResourceManager(ResourceManager&& other) noexcept
        : data(other.data),
          size(other.size)
    {
        other.data = nullptr;
        other.size = 0;
    }

    // Move Assignment Operator
    ResourceManager&
    operator=(ResourceManager&& other) noexcept
    {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }
};

int main()
{
    // Creating an object using default constructor
    ResourceManager obj1(5);

    // Creating an object using Copy constructor
    ResourceManager obj2 = obj1;

    // Creating an object using Copy assignment operator
    ResourceManager obj3(10);
    obj3 = obj1;

    // Creating an object using Move constructor
    ResourceManager obj4 = move(obj1);

    // Creating an object using Move assignment operator
    ResourceManager obj5;
    obj5 = move(obj2);

    return 0;
}