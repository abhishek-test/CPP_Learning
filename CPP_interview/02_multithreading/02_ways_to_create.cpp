#include <iostream>
#include <thread>

using namespace std;

/* // 1. Created using function pointer 
void fun (int x) {
    while (x-- > 0) {
        cout << x << endl;
    }    
}

int main() 
{
    std::thread t1(fun, 10);
    t1.join();
} 
cout << "********************************************** " << endl;"
*/


// // 2. Created using lambda function 
// // done 'in-place'
// int main () 
// {
//     // define lambda and then use it
//     /* auto fun = [](int x) {
//      while (x-- > 0) {
//             cout << x << endl;
//         }   
//     };

//     std::thread t1(fun, 10);
//     t1.join(); 
//     */

//     // create lambda inside thread creation itself
//     thread t1([](int x) {
//      while (x-- > 0) {
//             cout << x << endl;
//         }   
//     }, 10);

//     t1.join();
// } 

// // 3. created using functors (Function-objects)
// class Base {
// public:
//     void operator () (int x) {
//         while (x-- > 0) {
//             cout << x << endl;
//         }        
//     }
// };

// int main()
// {
//     std::thread t1((Base()), 10);
//     t1.join();
// }

// 4. using non-static member function of a class
class Base  {
public:
    void run(int x) {
        while(x-- > 0) {
            cout <<x << endl;
        }
    }
};

int main()
{
    Base b;
    std::thread t1(&Base::run, &b, 10); // when an object is created where does it sit ??
    t1.join();
}

// // 5. using static member functions 
// class Base {
// public:
//     static void run (int x) {
//         while (x-- > 0)        {
//             cout << x << endl;
//         }        
//     }
// };

// int main()
// {
//     // Base b; -> not required as static member function dont need class objects
//     std::thread t1(&Base::run, 10); // why is object address not required
//     t1.join();
// }