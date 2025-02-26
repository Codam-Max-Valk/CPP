#pragma once

#include <string.h>
#include <iostream>
#include <ostream>

#ifndef DEBUG
	#define DEBUG 0
#endif

struct Data {
	int id;
	std::string name;
	std::string value;
};
