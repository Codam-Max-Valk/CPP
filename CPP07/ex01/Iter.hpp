#pragma once

#include <iostream>
#include <ostream>

template <typename T>
void iter(T *address, size_t length, void (*func)(T &)){
	for (size_t i = 0; i < length; i++){
		func(address[i]);
	}
};

template <typename T>
void print(T &value){
	std::cout << value << " ";
};
