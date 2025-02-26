#include <iostream>
#include "Base.hpp"

int main() {
	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		std::cout << "Test " << i + 1 << std::endl;
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
	}
	{
		std::cout << "Test 11" << std::endl;
		Base *base = new Base();
		identify(base);
		identify(*base);
		delete base;
	}
	{
		std::cout << "Test 12" << std::endl;
		A *a = new A();
		identify(a);
		identify(*a);
		delete a;
	}
	{
		std::cout << "Test 13" << std::endl;
		B *b = new B();
		identify(b);
		identify(*b);
		delete b;
	}
	{
		std::cout << "Test 14" << std::endl;
		C *c = new C();
		identify(c);
		identify(*c);
		delete c;
	}
	return 0;
}
