/*
1. queue is FIFO (first in first out)
2. provides only specific set of functions
3. allows to push(insert) at back and pop(remove) from front
4. gives front(), back(), push(), pop(), empty(), size()
*/

#include <iostream>
#include <queue>

using namespace std;

void print(std::queue<int> que) {

    while (!que.empty()) {
        cout << que.front() << " ";
        que.pop(); //remove front else front will always be same
    }

    cout << endl;    
}

int main()
{
    std::queue<int> que;

    que.push(2);
    que.push(3);
    que.push(4);

    print(que);
}
