
#include <iostream>
#include <thread>

using namespace std;

void run (int x) {
    while(x-- > 0) {
        cout << x << endl;
    }    
    std::this_thread::sleep_for(chrono::seconds(1));
    cout << "Finished thread " << endl;
}

int main()
{       
    thread t1(run, 10); // request to OS for thread creation
    cout << "main()" << endl; 

    // t1.join() is used when we want main thread to wait for t1 to finish
    // if we dont want to wait use detach
    // behaviour is not fixed : if OS takes time in creating t1
    // and main thread returns then t1 ops are not performed 
    if(t1.joinable()) // to avoid multiple t1.join()/t1.detach() which throws an error
        t1.detach();  // detach t1 from main thread   

    cout << "main() after" << endl;    
}