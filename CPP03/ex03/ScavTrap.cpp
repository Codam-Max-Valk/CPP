#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitpoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(std::string const &target)
{
	if (checkStatus() == false)
		return;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints -= 1;
}	

void	ScavTrap::guardGate()
{
	if (checkStatus() == false)
		return;
	std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode!" << std::endl;
}
