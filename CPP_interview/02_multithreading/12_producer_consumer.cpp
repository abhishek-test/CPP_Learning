
#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <deque>

using namespace std;

std::mutex mu;
std::condition_variable cond;
deque<int> buffer;
const unsigned int maxBufferSize = 50;

void producer(int val) {
    while(val) {  // producer tries and get lock as it is in while loop
        std::unique_lock<std::mutex> locker(mu);
        cond.wait(locker, [](){ return buffer.size() < maxBufferSize;});
        buffer.push_back(val);
        cout << "Produced: " << val << endl;
        val--;
        locker.unlock();
        cond.notify_one();
    }
}

void consumer() {
    while (true) { // consumer tries and get lock once released from producer and keep the lock until 
                   // all data is consumed meanwhile producer tries to get the lock as well
        std::unique_lock<std::mutex> locker(mu);
        cond.wait(locker, []() {return buffer.size() > 0;});
        int val = buffer.front(); // buffer.back(); -> to consume elements in order of production
        buffer.pop_front(); // buffer.pop_front(); -> helps in consuming first item produced serially ?? 
        cout << "Consumed: " << val << endl;
        locker.unlock();
        cond.notify_one();
    }    
}

int main()
{
    // producer gets the lock produce and then again get the lock 
    // meanwhile consumer is tring to get the lock as well
    // when consumer get the lock it consumes and then again get the lock in while loop 
    // so producer produces for some time and then 
    // consumer get the lock and consumes
    // order of consumption is reverse to that of the producer ??? -> use buffer.pop_front() and val = buffer.front() to get the value

    std::thread t1(producer, 100);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}




