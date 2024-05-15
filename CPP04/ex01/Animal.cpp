#include "Animal.hpp"

Animal::Animal() {std::cout << "Animal default constructor called" << std::endl;}

Animal::Animal(std::string type) : type(type) {std::cout << "Animal type constructor called" << std::endl;}

Animal::~Animal() {std::cout << "Animal destructor called" << std::endl;}

Animal::Animal(const Animal &animal){
	std::cout << "Animal copy constructor called" << std::endl;
	*this = animal;
}

Animal &Animal::operator=(const Animal &animal){
	std::cout << "Animal assignation operator called" << std::endl;
	type = animal.type;
	return *this;
}

std::string Animal::getType() const {return type;}

void Animal::makeSound() const {
	std::cout << "*insert generic animal sounds here*" << std::endl;
}
