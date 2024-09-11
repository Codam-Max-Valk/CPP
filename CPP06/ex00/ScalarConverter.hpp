#pragma once

#include <string.h>
#include <iostream>
#include <ostream>

#ifndef DEBUG
	#define DEBUG 0
#endif

class NonDisplayableException : public std::exception{
	private:
		const char *_msg = "Non displayable";
	public:
		const char *what() const noexcept;
};

class ImpossibleException : public std::exception{
	private:
		const char *_msg = "impossible";
	public:
		const char *what() const noexcept;
};

class ScalarConverter{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other) = delete;
		ScalarConverter &operator=(const ScalarConverter &other) = delete;
	public:
		~ScalarConverter();
		static void convert(std::string const &value);
};
