#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name){
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";

	this->_hitpoints = this->FragTrap::_hitpoints;
	this->_energyPoints = this->ScavTrap::_energyPoints;
	this->_attackDamage = this->FragTrap::_attackDamage;
}
