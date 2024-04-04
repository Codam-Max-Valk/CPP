#include "Weapon.hpp"

void Weapon::setType(std::string type){
	this->_type = type;
}

const std::string &Weapon::getType(){
	return this->_type;
}
