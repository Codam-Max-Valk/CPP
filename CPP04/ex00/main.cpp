#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();

//____________WRONG____________________
	const WrongAnimal* k = new WrongCat();

	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	k->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	return 0;
}
