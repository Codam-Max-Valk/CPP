#include "Harl.hpp"

int main(int ac, char **av) {
	Harl harl;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (ac == 2){
		for (int i = 0; i < 4; i++){
			if (av[1] == levels[i]){
				harl.complain(av[1]);
				break;
			}
		}
	} else {
		std::cout << "Usage: ./ex06 [DEBUG|INFO|WARNING|ERROR]" << std::endl;
	}
	return 0;
}
