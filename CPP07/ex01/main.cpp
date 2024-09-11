#include "Iter.hpp"



int main(){
	int a[] = {1, 2, 3, 4, 5};
	iter(a, 5, print);
	std::cout << std::endl;

	std::string b[] = {"one", "two", "three", "four", "five"};
	iter(b, 5, print);
	std::cout << std::endl;

	double c[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	iter(c, 5, print);
	std::cout << std::endl;

	return 0;
}
