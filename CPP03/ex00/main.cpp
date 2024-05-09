
#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("Dummy");

	
	clapTrap.attack("Bandit");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(3);

	for (int i = 0; i < 8; i++)
		clapTrap.attack("Bandit");
	clapTrap.beRepaired(2);
	clapTrap.takeDamage(10);
	clapTrap.attack("Bandit");
    return 0;
}