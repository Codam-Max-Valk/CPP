#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>


void TestEdgeCases() {
	// Test case 1: Testing with vector of size 1
	std::vector<int> vec1 = {10};
	try {
		auto result = easyfind(vec1, 10);
		std::cout << "Element found: " << *result << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// Test case 2: Testing with list of size 1
	std::list<int> lst1 = {20};
	try {
		auto result = easyfind(lst1, 20);
		std::cout << "Element found: " << *result << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// Test case 3: Testing with empty vector
	std::vector<int> emptyVec;
	try {
		auto result = easyfind(emptyVec, 30);
		std::cout << "Element found: " << *result << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// Test case 4: Testing with empty list
	std::list<int> emptyList;
	try {
		auto result = easyfind(emptyList, 40);
		std::cout << "Element found: " << *result << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}


int main() {

	TestEdgeCases();
	// Test case 1: Testing with vector
	std::vector<int> vec = {1, 2, 3, 4, 5};
	try {
		auto result = easyfind(vec, 4);
		std::cout << "Element found: " << *result << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// Test case 2: Testing with list
	std::list<int> lst = {10, 20, 30, 40, 50};
	try {
		auto result = easyfind(lst, 25);
		std::cout << "Element found: " << *result << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// Test case 3: Testing with empty container
	std::vector<int> emptyVec;
	try {
		auto result = easyfind(emptyVec, 10);
		std::cout << "Element found: " << *result << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
