#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
	std::string _name;

	public:
	Zombie();
	~Zombie();

	void announce();
	void setName(std::string name);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
