#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

namespace std{};	using namespace std;
// int main()
// {
// 	// const Animal* meta = new Animal();
// 	const Animal* i = new Cat();
// 	const Animal* j = new Dog();


// //____________WRONG____________________
// 	// const WrongAnimal* k = new WrongCat();

// 	// std::cout << i->getType() << " " << std::endl;
// 	std::cout << j->getType() << " " << std::endl;
// 	// std::cout << k->getType() << " " << std::endl;

// 	// i->makeSound();
// 	j->makeSound();
// 	// k->makeSound();
// 	// meta->makeSound();

// 	// delete meta;
// 	delete static_cast<const Dog*>(j);
// 	delete i;
// 	return 0;
// }


int main(void)
{
	const Animal* Puppy = new Dog();
	cout << endl;

	const Animal* Poesi = new Cat();
	cout << endl;

	cout << "------------------- pet -------------------" << endl;
	const Animal* pet[4];

	cout << "------------------- DOGS -------------------" << endl;
	for (size_t i = 0; i < 2; i++) {
		pet[i] = new Dog();
		cout << endl;
	}

	cout << "------------------- CATS -------------------" << endl;
	for (size_t i = 2; i < 4; i++) {
		pet[i] = new Cat();
		cout << endl;
	}

	cout << "---------------- DELETE pet ---------------" << endl;
	for (size_t i = 0; i < 4; i++) {
		delete pet[i];
	}
	cout << "--------------- pet DELETED ---------------" << endl;
	cout << endl;

	delete Puppy;
	delete Poesi;

	return EXIT_SUCCESS; 
}