#include "ScalarConverter.hpp"

int main(int argc, char **argv){
	if (DEBUG)
		std::cout << "main called" << std::endl;
	if (argc != 2)
	{
		std::cout << "Usage: ./convert [value]" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
