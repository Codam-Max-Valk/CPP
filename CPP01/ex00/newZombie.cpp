#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *zombie = new Zombie();

	if (!zombie) return nullptr;
	zombie->setName(name);
	return zombie;
}
