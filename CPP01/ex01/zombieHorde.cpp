#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	if (N <= 0)
		return NULL;
	try
	{
		Zombie *Horde = new Zombie[N];
		for (int i = 0; i < N; i++) {
			Horde[i].setName(name);
		}
		return Horde;
	}
	catch (std::bad_alloc& e)
	{
		std::cerr << "Failed to allocate memory for Zombie Horde: " << e.what() << std::endl;
		return NULL;
	}
}
