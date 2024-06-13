#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* Puppy = new Dog();
	std::cout << std::endl;

	const Animal* Poesi = new Cat();
	std::cout << std::endl;

	std::cout << "------------------- WRONG -------------------" << std::endl;
	{
		const WrongAnimal* fakecat = new WrongCat();
		fakecat->makeSound();
		std::cout << std::endl;
		delete fakecat;
	}
	std::cout << std::endl;
	std::cout << "------------------- pet -------------------" << std::endl;
	const Animal* pet[4];

	std::cout << "------------------- DOGS -------------------" << std::endl;
	for (size_t i = 0; i < 2; i++) {
		pet[i] = new Dog();
		std::cout << std::endl;
	}

	std::cout << "------------------- CATS -------------------" << std::endl;
	for (size_t i = 2; i < 4; i++) {
		pet[i] = new Cat();
		std::cout << std::endl;
	}

	std::cout << "---------------- DELETE pet ---------------" << std::endl;
	for (size_t i = 0; i < 4; i++) {
		delete pet[i];
	}
	std::cout << "--------------- pet DELETED ---------------" << std::endl;
	std::cout << std::endl;

	delete Puppy;
	delete Poesi;

	return EXIT_SUCCESS; 
}