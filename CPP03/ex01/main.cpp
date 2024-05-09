
#include "ScavTrap.hpp"

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
		std::cout << "ClapTrap" << std::endl;
		ClapTrap clapTrap("Dummy");

		clapTrap.attack("Bandit");
		clapTrap.takeDamage(5);
		clapTrap.beRepaired(3);
	}

    return 0;
}