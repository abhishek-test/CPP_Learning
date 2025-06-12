
#include <iostream>

using namespace std;

int main()
{
	int x = 10;
	int y = 50;

	// pointer to a const -> 
	// can't change the const but can change to point to sth else
	const int* ptr_to_const = &x;
	//*ptr_to_const = 20;  // wrong
	ptr_to_const = &y;

	// const pointer 
	// can't change to point to sth else but value can be changed
	int* const const_ptr = &x;
	*const_ptr = 20;
	//ptr = &y; // wrong


	// const pointer to a constant
	// cant' point to sth else neither value can be changed
	const int* const const_ptr_const = &x;
	//*const_ptr_const = 20; // wrong
	//const_ptr_const = &y;  // wrong

	return 0;
}