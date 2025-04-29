#include "ScalarConverter.hpp"

void testSomeValues() {
	std::cout << "Testing some values" << std::endl;
	ScalarConverter::convert("0");
	std::cout << "-----------------------------------------" << std::endl;
	ScalarConverter::convert("42");
	std::cout << "-----------------------------------------" << std::endl;
	ScalarConverter::convert("-42");
	std::cout << "-----------------------------------------" << std::endl;
	ScalarConverter::convert("-42.42f");
	std::cout << "-----------------------------------------" << std::endl;
	ScalarConverter::convert("42.0");
	std::cout << "-----------------------------------------" << std::endl;
	ScalarConverter::convert("42.42");
	std::cout << "-----------------------------------------" << std::endl;
	ScalarConverter::convert("42.42f");
	std::cout << "-----------------------------------------" << std::endl;
	ScalarConverter::convert("2147483647");
	std::cout << "-----------------------------------------" << std::endl;
	ScalarConverter::convert("-2147483648");
	std::cout << "-----------------------------------------" << std::endl;
	ScalarConverter::convert("2147483648");
	std::cout << "-----------------------------------------" << std::endl;
	ScalarConverter::convert("-2147483649");
	std::cout << "-----------------------------------------" << std::endl;
	ScalarConverter::convert("a");
	std::cout << "-----------------------------------------" << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << "-----------------------------------------" << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << "-----------------------------------------" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << "-----------------------------------------" << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << "-----------------------------------------" << std::endl;
	ScalarConverter::convert("111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
	std::cout << "-----------------------------------------" << std::endl;
	ScalarConverter::convert("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111112");

}

int main(int argc, char **argv) {
	if (DEBUG)
		std::cout << "main called" << std::endl;
	if (argc != 2)
	{
		testSomeValues();
		std::cout << "you can also test more yourself this way:" << std::endl;
		std::cout << "Usage: ./convert [value]" << std::endl;
		return 0;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
