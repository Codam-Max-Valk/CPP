#include "Zombie.hpp"

void	lk(){
	system("leaks -q BraiiiiiiinnnzzzZ");
}

int main() {
	atexit(lk);
	Zombie *zombie = newZombie("Zombie");

	zombie->announce();
	randomChump("Chump");
	delete zombie;
	return 0;
}

