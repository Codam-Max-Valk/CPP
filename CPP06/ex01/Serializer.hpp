#pragma once

#include <string.h>
#include <iostream>
#include <ostream>
#include <cstdint> 
#include "Data.hpp"

#ifndef DEBUG
	#define DEBUG 0
#endif

class Serializer{
	private:
		Serializer();
		Serializer(Serializer const &other) = delete;
		Serializer &operator=(const Serializer &other) = delete;
	public:
		~Serializer();
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};
