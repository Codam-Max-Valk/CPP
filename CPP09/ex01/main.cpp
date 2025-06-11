#include <exception>
#include "RPN.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: ./rpn \"expression\"" << std::endl;
		return 1;
	}
	try {
		RPN rpn;
		rpn.evaluate(argv[1]);
		std::cout << rpn.getResult() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
}