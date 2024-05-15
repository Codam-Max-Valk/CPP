
#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <string>

int main()
{
	std::string input;
	DiamondTrap dia("DIAMONDS!");
	dia.whoAmI();
	dia.highFivesGuys();
	dia.guardGate();

	while (true)
	{
		std::string amount;
		std::cout << "Do you want to continue? (exit/attack/take/repair/who/high/guard): ";
		std::cin >> input;
		if (input == "exit")
			break;
		else if (input == "attack")
			dia.attack("target");
		else if (input == "who")
			dia.whoAmI();
		else if (input == "high")
			dia.highFivesGuys();
		else if (input == "guard")
			dia.guardGate();
		else if (input == "take" || input == "repair")
		{
			std::cout << "Enter amount: ";
			std::cin >> amount;
			if (input == "repair")
				dia.beRepaired(std::stoi(amount));
			else if (input == "take")
				dia.takeDamage(std::stoi(amount));
		}
		else
			std::cout << "Invalid input" << std::endl;
	}
    return 0;
}