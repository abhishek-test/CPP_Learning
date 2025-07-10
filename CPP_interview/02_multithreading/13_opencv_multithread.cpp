
#include <opencv2/opencv.hpp>
#include <thread>
#include <deque>
#include <mutex>
#include <condition_variable>
#include <iostream>

class BoundedQueue {

private:
	size_t capacity;
	std::mutex mtx;
	std::deque<cv::Mat> queue;
	std::condition_variable cv_full, cv_empty;

public:
	BoundedQueue(size_t cap) : capacity(cap) {}

	void push(const cv::Mat& item) {
		std::unique_lock<std::mutex> lock(mtx);
		cv_full.wait(lock, [&] { return queue.size() < capacity; });
		queue.push_back(item);
		cv_empty.notify_one();
	}

	bool pop(cv::Mat &item) {
		std::unique_lock<std::mutex> lock(mtx);
		cv_empty.wait(lock, [&] { return !queue.empty(); });
		item = queue.front();
		queue.pop_front();
		cv_full.notify_one();

		return true;
	}

	void clear() {
		std::lock_guard<std::mutex> lock(mtx);
		queue.clear();
		cv_full.notify_all();
	}
};

BoundedQueue captureQueue(20);
BoundedQueue processingQueue(20);
std::atomic<bool> running { true };

static void captureThread() {
	cv::VideoCapture capObj(0);
	if (!capObj.isOpened()) { 
		running = false; 
		return;  
	}

	while (running) {
		cv::Mat frame;
		capObj >> frame;
		captureQueue.push(frame);
	}

	capObj.release();
}

static void processingThread() {
	while (running) {
		cv::Mat frame, hsv;
		if (captureQueue.pop(frame)) {
			cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);
			processingQueue.push(hsv);
		}
	}
}

static void displayThread() {
	while (running) {
		cv::Mat frame;
		if (processingQueue.pop(frame)) {
			cv::imshow("Processing", frame);
			if (cv::waitKey(1) == 27) {
				running = false;
				break;
			}
		}
	}
}

int main() {

	std::thread t1(captureThread);
	std::thread t2(processingThread);
	std::thread t3(displayThread);

	t1.join();
	t2.join();
	t3.join();
}