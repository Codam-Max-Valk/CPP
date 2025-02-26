#include "Serializer.hpp"

Serializer::Serializer() {
	if (DEBUG)
		std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::~Serializer() {
	if (DEBUG)
		std::cout << "Serializer destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data *ptr) {
	if (DEBUG)
		std::cout << "Serializer serialize called" << std::endl;
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
	if (DEBUG)
		std::cout << "Serializer deserialize called" << std::endl;
	return reinterpret_cast<Data *>(raw);
}

