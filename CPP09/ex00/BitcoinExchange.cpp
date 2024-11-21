#include "BitcoinExchange.hpp"



BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(std::string filename, std::string cmp_filename) :_data(), _second_data(), _database(filename), _second_database(cmp_filename){
	std::ifstream file(filename);
	std::ifstream cmp_file(cmp_filename);

	if (!file.is_open() || !cmp_file.is_open())
		throw FileOpenException();
	std::string line;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string key;
		double value;
		ss >> key >> value;
		if (ss.fail() || ss.peek() != EOF)
			throw BadInputException();

		_data[key] = value;
	}
	while (std::getline(cmp_file, line)) {
		std::stringstream ss(line);
		std::string key;
		double value;
		ss >> key >> value;
		if (ss.fail() || ss.peek() != EOF)
			throw BadInputException();
		_second_data[key] = value;
	}
};
	
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _data(copy._data), _second_data(copy._second_data), _database(copy._database), _second_database(copy._second_database){};

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
	_data = copy._data;
	_second_data = copy._second_data;
	_database = copy._database;
	_second_database = copy._second_database;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {};

const char *BadInputException::what() const noexcept {
	return _msg.c_str();
}

const char *FileOpenException::what() const noexcept {
	return _msg.c_str();
}


