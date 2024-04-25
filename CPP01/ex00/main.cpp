#include "Zombie.hpp"

int main() {
	Zombie *zombie = newZombie("Zombie");

	zombie->announce();
	randomChump("Chump");
	delete zombie;
	return 0;
}

