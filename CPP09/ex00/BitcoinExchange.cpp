#include "BitcoinExchange.hpp"
#include <fstream>
#include <ios>

void BitcoinExchange::parseData() {
	std::ifstream file(_database);
	if (!file.is_open())
		throw FileOpenException();
	std::string line;
	
    std::getline(file, line);
    while (std::getline(file, line)) {
        size_t comma_pos = line.find(',');
        if (comma_pos != std::string::npos) {
            std::string date = line.substr(0, comma_pos);
            std::string valueStr = line.substr(comma_pos + 1);
            try {
                double value = std::stod(valueStr);
                _data[date] = value;
            } catch (const std::invalid_argument& e) {
                throw BadInputException("Database file broken: " + line);
            }
        } else {
            throw BadInputException("Invalid line format");
        }
    }
}

void BitcoinExchange::processInputFile() {
    std::ifstream file(_input_database);
    if (!file.is_open())
        throw FileOpenException();

    std::string line;
    std::getline(file, line); 
    
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#')
            continue;
            
        try {
            size_t delimiter = line.find(" | ");
            if (delimiter == std::string::npos)
                throw BadInputException("Invalid input format: " + line);
            
            std::string input_date = line.substr(0, delimiter);
            std::string valueStr = line.substr(delimiter + 3);
            
            if (input_date.empty() || input_date.length() != 10 || 
                input_date[4] != '-' || input_date[7] != '-')
                throw BadInputException(input_date);
            std::stringstream valueStream(valueStr);
            double input_value;
            valueStream >> input_value;
            if (valueStream.fail() || !valueStream.eof())
                throw BadInputException("Invalid number format: " + valueStr);
            if (input_value < 0)
                throw NegativeNumberException();
            else if (input_value > 1000)
                throw NumberTooLargeException();
            auto it = _data.lower_bound(input_date);
            if (it == _data.end())
                it--;
            else if (it->first != input_date && it == _data.begin())
                throw BadInputException("No exchange rate available for date: " + input_date);
            else if (it->first != input_date)
                it--;
            double amount = input_value * it->second;
            std::cout << input_date << " => " << std::defaultfloat << input_value << " = " 
                    << std::fixed << std::setprecision(2) << amount << std::endl;
                    
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}

BitcoinExchange::BitcoinExchange(std::string filename, std::string cmp_filename) 
    : _data(), _database(filename), _input_database(cmp_filename) {
    
	parseData();
	processInputFile();
}
	
BitcoinExchange::~BitcoinExchange() {};

const char *BadInputException::what() const noexcept {
	return _msg.c_str();
}

const char *FileOpenException::what() const noexcept {
	return _msg.c_str();
}

const char *NumberTooLargeException::what() const noexcept {
	return _msg.c_str();
}

const char *NegativeNumberException::what() const noexcept {
	return _msg.c_str();
}


