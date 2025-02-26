#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() {std::cout << "ClapTrap default constructor called" << std::endl;};

ClapTrap::~ClapTrap() {std::cout << "ClapTrap destructor called" << std::endl;};

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	_name = copy._name;
	_hitpoints = copy._hitpoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
	return *this;
}

bool	ClapTrap::checkStatus()
{
	if (_hitpoints < 1)
	{
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
		return false;
	}
	if (_energyPoints < 1)
	{
		std::cout << "ClapTrap " << _name << " is out of energy points!" << std::endl;
		return false;
	}
	return true;
}

void	ClapTrap::attack(std::string const &target)
{
	if (checkStatus() == false)
		return;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (checkStatus() == false)
		return;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	if (amount > _hitpoints)
		_hitpoints = 0;
	else
		_hitpoints -= amount;
	if (_hitpoints < 1)
		std::cout << "ClapTrap " << _name << " died from all that damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (checkStatus() == false)
		return;
	std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points of health!" << std::endl;
	_hitpoints += amount;
	_energyPoints -= 1;
}
