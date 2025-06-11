#pragma once

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <exception>

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
		BadInputException(std::string context) : _msg("Bad input: " + context) {}
		const char *what() const noexcept;
};

class NumberTooLargeException : public std::exception
{
	private:
		std::string _msg = "too large a number";
	public:
		const char *what() const noexcept;
};

class NegativeNumberException : public std::exception
{
	private:
		std::string _msg = "not a positive number.";
	public:
		const char *what() const noexcept;
};

class BitcoinExchange
{
	private:
		std::map<std::string, double> _data;
		std::string _database;
		std::string _input_database;

		BitcoinExchange() = delete;
		BitcoinExchange(const BitcoinExchange &copy) = delete;
		BitcoinExchange &operator=(const BitcoinExchange &copy) = delete;
	public:
		BitcoinExchange(std::string filename, std::string cmp_filename);
		~BitcoinExchange();
		void processInputFile();
		void parseData();
		void parseInputData();
		void calculateAmount();
		void printData() const;
};

