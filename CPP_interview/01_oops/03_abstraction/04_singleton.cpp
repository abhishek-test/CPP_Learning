
#include <iostream>
#include <mutex>

using namespace std;

class Logger {

private:

	std::mutex mtx;
	Logger() {} // private constructor
	
public:

	Logger(const Logger&) = delete; // delete copy constructor
	Logger operator=(const Logger&) = delete; // delete assignment operator

	static Logger& getInstance() {
		static Logger instance;
		return instance;
	}

	void log(std::string message) {
		std::lock_guard<std::mutex> lock(mtx);
		cout << "[Log] : " << message << endl;
	}
};

int main() {

	Logger::getInstance().log("Application started");
	Logger::getInstance().log("Processing frame...");
}
