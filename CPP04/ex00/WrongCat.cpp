#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal(wrongCat) {
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat) {
	this->type = wrongCat.type;
	return *this;
}

WrongCat::~WrongCat() {
}
