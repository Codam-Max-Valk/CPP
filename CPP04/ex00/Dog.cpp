#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {std::cout << "Dog default constructor called" << std::endl;}

Dog::~Dog() {std::cout << "Dog destructor called" << std::endl;}

Dog::Dog(const Dog &dog) : Animal(dog) {std::cout << "Dog copy constructor called" << std::endl;}

Dog &Dog::operator=(const Dog &dog) {
	std::cout << "Dog assignation operator called" << std::endl;
	Animal::operator=(dog);
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Blaf Blaf" << std::endl;
}
