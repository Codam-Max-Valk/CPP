#include <iostream>
#include "Array.hpp"
#include <string>

#define MAX_VAL 10

template <typename T>
void print(T &value) {
	std::cout << value << " ";
}


int main(void)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL]();
	srand(time(nullptr));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		print(numbers[i]);
		if (mirror[i] != numbers[i])
		{
			std::cout << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (numbers[i] != mirror[i]) {
			std::cout << "mirror wasn't changed" << std::endl;
			break;
		}
	}
	delete [] mirror;
	Array<std::string> words(MAX_VAL);
	Array<std::string> fake;

	fake = words;
	for (int i = 0; i < MAX_VAL; i++)
	{
		const std::string value = "word" + std::to_string(i);
		words[i] = value;
		fake[i] = value;
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		print(words[i]);
		if (fake[i] != words[i])
		{
			std::cout << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		words[i] = "new_word" + std::to_string(i);
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (words[i] != fake[i]) {
			std::cout << "fake wasn't changed" << std::endl;
			break;
		}
	}
	return 0;
}
