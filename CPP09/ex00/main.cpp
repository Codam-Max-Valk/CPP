#include "BitcoinExchange.hpp"


int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: ./bitcoin [filename]" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange exchange("./cpp_09/data.csv", argv[1]);
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
