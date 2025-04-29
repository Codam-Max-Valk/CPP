#include "whatever.hpp"

int main() {
	int a = 2;
	int b = 3;

	double f = 2.5;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "c = " << c << ", d = " << d << std::endl;

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	std::cout << "f = " << f << std::endl;
	::swap(a, f);
	std::cout << "f = " << f << std::endl;
	std::cout << "min(a, f) = " << ::min(a, f) << std::endl;
	std::cout << "max(a, f) = " << ::max(a, f) << std::endl;


	return 0;
}