#pragma once

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string type;
		Animal();
		Animal(std::string type);
	public:
		virtual ~Animal();
		Animal(const Animal &animal);
		Animal &operator=(const Animal &animal);
		std::string getType() const;
		virtual void makeSound() const = 0;
};
