// In C++ 14, we have generic/Polymorphic lambda
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    vector<int> v = {1, 2, 3, 4, 5};
    std::for_each(v.begin(), v.end(), [] (int i) { cout << i*2 << " "; } );

    auto add = [] (auto x, auto y) { return x+y; };

    int a = 1, b=2;
    string f1 = "adfaf", f2 = "sdgsg";

    cout<< add(a,b) << endl;
    cout<< add(f1,f2) << endl;

    //*************************************** pass by value 
    int initial_sum = 100;

    // capture initial_sum by value
    auto add_to_sum = [initial_sum] (int num) {
        // here inital_sum = 100 from local scope
        return initial_sum + num;
    };

    int final_sum = add_to_sum(78);
    cout << "100 + 78 = " << final_sum;

    //**************************************** pass by ref
    // [&num] captures num by reference
    auto increment_by_one = [&final_sum] () {
        cout << "Incrementing num by 1.\n";
        final_sum++;
    };

    // invoke lambda function
    increment_by_one();
    cout << "Now, num = " << final_sum << endl; 

    // use [=] and [&] to use all vars by copy and reference respectively

}

/*
capture list: []
function arguments: ()
function body: {}

1. Increases code clarity
2. Free variables
3. Doesn't use new names so less memory occupancy and managment
*/
