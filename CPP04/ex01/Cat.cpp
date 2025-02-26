#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat) {
	brain = new Brain(*cat.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat) {
	std::cout << "Cat assignation operator called" << std::endl;
	Animal::operator=(cat);
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Miiiiiiiaaaaaaaaaaaaaaauuuuuuuuuuuw" << std::endl;
}

