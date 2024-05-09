#pragma once

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap{
	private:
		std::string	_name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();

		using	ScavTrap::attack;
		void	whoAmI();
};