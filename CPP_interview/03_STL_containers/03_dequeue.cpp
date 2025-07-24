/*
1. Indexed sequence container
2. Fast insertion - both at beginning and end
3. Elements are not stored contigous
4. Storage is automatically expanded and contracted as needed
5. Expansion is cheaper than vector
6. A dequeue holding just one element has to allocate its full internal aray
   e.g. 8 times the obj size on 64-bit libstdc++; 16 times obj
   size or 4096 bytes whichever is larger on 64-bit libc++

   Random access: constant O(1)
   Insertion or removal at end/beginning: O(1)
   Insertion or removal of elements - linear O(n)
*/

#include <iostream>
#include <deque>

using namespace std;

void print(std::deque<int> dqu) {
    for(int num:dqu)
        cout << num << " ";

    cout << endl;
}

int main()
{
    {
        std::deque<int> dqu = {2,3,4};
        dqu.push_back(5);
        dqu.push_front(1);
        print(dqu);
    }

    {
        std::deque<int> dqu = {2,3,4};
        dqu.pop_back();
        dqu.pop_front();
        print(dqu);
    }
}