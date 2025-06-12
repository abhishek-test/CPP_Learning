#include <string>

using namespace std;

template <typename T>
class Box {

private:
	T data;
	
public:
	Box(T input) {
		data = input;
	}

	void show() {
		std::cout << data << std::endl;
	}
};


int main()
{
	Box<double> bf(2.3);
	Box<int> bi(2);
	Box<std::string> bs("Hello!");

	bf.show();
	bi.show();
	bs.show();

	return 0;
}