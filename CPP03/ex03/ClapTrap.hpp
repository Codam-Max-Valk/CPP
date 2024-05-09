#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
	protected:
		std::string _name;
		unsigned int _hitpoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &copy);

		void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		bool checkStatus();
};
