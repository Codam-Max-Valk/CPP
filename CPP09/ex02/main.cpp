#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Usage: ./pmergeMe <list of positive integers>" << std::endl;
		return 1;
	}

	PmergeMe pmerge;
	try {
		pmerge.run(argc, argv);
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}