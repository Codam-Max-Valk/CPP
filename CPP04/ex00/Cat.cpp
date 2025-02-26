#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {std::cout << "Cat default constructor called" << std::endl;}

Cat::~Cat() {std::cout << "Cat destructor called" << std::endl;}

Cat::Cat(const Cat &cat) : Animal(cat) {std::cout << "Cat copy constructor called" << std::endl;}

Cat &Cat::operator=(const Cat &cat) {
	std::cout << "Cat assignation operator called" << std::endl;
	Animal::operator=(cat);
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Miiiiiiiaaaaaaaaaaaaaaauuuuuuuuuuuw" << std::endl;
}

