
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "ScavTrap\n" << std::endl;
		ScavTrap scavTrap("Scav");

		scavTrap.attack("Bandit");
		scavTrap.takeDamage(50);
		scavTrap.beRepaired(30);
		scavTrap.guardGate();

		scavTrap.takeDamage(101);
		scavTrap.attack("Bandit");
		scavTrap.guardGate();
	}
	std::cout << std::endl;
	{
		std::cout << "ClapTrap\n" << std::endl;
		ClapTrap clapTrap("Dummy");

		clapTrap.attack("Bandit");
		clapTrap.takeDamage(5);
		clapTrap.beRepaired(3);
	}
	std::cout << std::endl;
	{
		std::cout << "FragTrap\n" << std::endl;
		FragTrap fragTrap("Frag");

		fragTrap.attack("Bandit");
		fragTrap.takeDamage(50);
		fragTrap.beRepaired(30);
		fragTrap.highFivesGuys();

		fragTrap.takeDamage(101);
		fragTrap.attack("Bandit");
		fragTrap.highFivesGuys();
	}
    return 0;
}