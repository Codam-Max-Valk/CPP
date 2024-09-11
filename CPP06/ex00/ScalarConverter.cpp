#include "ScalarConverter.hpp"
#include <cctype>
#include <exception>
#include <iostream>
#include <string>

const char *NonDisplayableException::what() const noexcept{
	return _msg;
}

const char *ImpossibleException::what() const noexcept{
	return _msg;
}

ScalarConverter::ScalarConverter(){
	if (DEBUG)
		std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter(){
	if (DEBUG)
		std::cout << "ScalarConverter destructor called" << std::endl;
}

void ConvertChar(const std::string &value){
	std::cout << "char: ";
	try{
		int i = std::stoi(value);
		if (std::isprint(i))
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		else
			throw NonDisplayableException();
	}
	catch(std::exception &e){
		if (e.what() == NonDisplayableException().what())
			std::cout << NonDisplayableException().what() << std::endl;
		else
			std::cout << ImpossibleException().what() << std::endl;
	}
}

void ConvertInt(const std::string &value){
	std::cout << "int: ";
	try{
		int i = std::stoi(value);
		std::cout << i << std::endl;
	}
	catch(std::exception &e){
		std::cout << ImpossibleException().what() << std::endl;
	}
}

void ConvertFloat(const std::string &value){
	std::cout << "float: ";
	try{
		float f = std::stof(value);
		std::cout << f;
		if (f - static_cast<int>(f) == 0)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
	catch(std::exception &e){
		std::cout << ImpossibleException().what() << std::endl;
	}
}

void ConvertDouble(const std::string &value){
	std::cout << "double: ";
	try{
		double d = std::stod(value);
		std::cout << d;
		if (d - static_cast<int>(d) == 0)
			std::cout << ".0";
		std::cout << std::endl;
	}
	catch(std::exception &e){
		std::cout << ImpossibleException().what() << std::endl;
	}
}

void ScalarConverter::convert(const std::string &value){
	ConvertChar(value);
	ConvertInt(value);
	ConvertFloat(value);
	ConvertDouble(value);
}

