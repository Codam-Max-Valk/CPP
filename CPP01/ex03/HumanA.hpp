#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
	private:
		std::string _name;
		Weapon &_weapon;
	public:
		HumanA();
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void attack();
		void setName(std::string name);
		void setWeapon(Weapon &weapon);
};

#endif
