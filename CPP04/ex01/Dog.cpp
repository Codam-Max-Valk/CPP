#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog) {
	brain = new Brain(*dog.brain);
	std::cout << "Dog copy constructor called" << std::endl;
	}

Dog &Dog::operator=(const Dog &dog){
	std::cout << "Dog assignation operator called" << std::endl;
	Animal::operator=(dog);
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Blaf Blaf" << std::endl;
}
