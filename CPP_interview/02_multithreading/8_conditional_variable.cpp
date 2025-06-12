#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

std::condition_variable cv;
std::mutex m;
long balance = 0;

void addMoney(int money) {
    std::lock_guard<mutex> lg(m);
    balance += money;
    cout << "Amnt Added Current Balance: " << balance << endl;
    cv.notify_one();  // notifies other thread that its job is done
}

void withdrawMoney(int money) {
    std::unique_lock<mutex> ul(m);
    // cv.wait waits for thead with lock to finish and then check the condition again
    cv.wait(ul, [] { return (balance!=0) ? true:false; } );   // using wait on condition vars
    
    if(balance >= money) {
        balance -= money;
        cout << "Amnt Deducted: " << money << endl;
    }
    else {
        cout << "Not enough Balance to withdraw, Current Bal is less than: " << money <<  endl;         
    }

    cout << "Current Balance is : " << balance << endl;
}


int main()
{
    std::thread t1(withdrawMoney, 500);

    // even if withdraw thread starts first, it goes in wait mode for add to finish until balance is >= money 
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::thread t2(addMoney, 500);

    t1.join();
    t2.join();
}