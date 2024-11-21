#pragma once

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <exception>

class NotAPositiveNumberException : public std::exception
{
	private:
		std::string _msg = "Not a positive number";
	public:
		const char *what() const noexcept;
};

class NumberTooLargeException : public std::exception
{
	private:
		std::string _msg = "Number too large";
	public:
		const char *what() const noexcept;
};

class FileOpenException : public std::exception
{
	private:
		std::string _msg = "File open error";
	public:
		const char *what() const noexcept;
};

class BadInputException : public std::exception
{
	private:
		std::string _msg = "Bad input";
	public:
		const char *what() const noexcept;
};

class BitcoinExchange
{
	private:
		std::map<std::string, double> _data;
		std::map<std::string, double> _second_data;
		std::string _database;
		std::string _second_database;
	public:
		BitcoinExchange();
		BitcoinExchange(std::string filename, std::string cmp_filename);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		~BitcoinExchange();
};

