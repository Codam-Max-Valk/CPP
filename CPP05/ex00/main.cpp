#include <cassert>
#include <iostream>
#include "Bureaucrat.hpp"

// Test case 1: Creating a Bureaucrat with a valid grade
void testBureaucratConstructorValidGrade() {
	Bureaucrat b("John Doe", 50);
	std::cout << "Name: " << b.getName() << ", Grade: " << b.getGrade() << std::endl;
	assert(b.getName() == "John Doe");
	assert(b.getGrade() == 50);
	std::cout << "Test case 1: Bureaucrat with valid grade - [OK]" << std::endl;
}

// Test case 2: Creating a Bureaucrat with the minimum grade
void testBureaucratConstructorMinGrade() {
	Bureaucrat b("Jane Smith", 1);
	std::cout << "Name: " << b.getName() << ", Grade: " << b.getGrade() << std::endl;
	assert(b.getName() == "Jane Smith");
	assert(b.getGrade() == 1);
	std::cout << "Test case 2: Bureaucrat with minimum grade - [OK]" << std::endl;
}

// Test case 3: Creating a Bureaucrat with the maximum grade
void testBureaucratConstructorMaxGrade() {
	Bureaucrat b("Alice Johnson", 150);
	std::cout << "Name: " << b.getName() << ", Grade: " << b.getGrade() << std::endl;
	assert(b.getName() == "Alice Johnson");
	assert(b.getGrade() == 150);
	std::cout << "Test case 3: Bureaucrat with maximum grade - [OK]" << std::endl;
}

// Test case 4: Creating a Bureaucrat with a grade below the minimum
void testBureaucratConstructorBelowMinGrade() {
	try {
		Bureaucrat b("Bob Brown", 0);
		// The constructor should throw an exception, so this line should not be reached
		assert(false);
	} catch (std::exception &e) {
		std::cout << "Exception thrown: " << e.what() << std::endl;
		assert(std::string(e.what()) == "Grade is too high");
		std::cout << "Test case 4: Bureaucrat with grade below minimum - [OK]" << std::endl;
	}
}

// Test case 5: Creating a Bureaucrat with a grade above the maximum
void testBureaucratConstructorAboveMaxGrade() {
	try {
		Bureaucrat b("Eve Davis", 151);
		// The constructor should throw an exception, so this line should not be reached
		assert(false);
	} catch (std::exception &e) {
		std::cout << "Exception thrown: " << e.what() << std::endl;
		assert(std::string(e.what()) == "Grade is too low");
		std::cout << "Test case 5: Bureaucrat with grade above maximum - [OK]" << std::endl;
	}
}

// Test case 6: Overloading the insertion operator for Bureaucrat
void testBureaucratInsertionOperator() {
	Bureaucrat b("Mary Johnson", 75);
	std::cout << b;
	std::cout << "Test case 6: Overloading insertion operator for Bureaucrat - [OK]" << std::endl;
}

int main() {
	testBureaucratConstructorValidGrade();
	testBureaucratConstructorMinGrade();
	testBureaucratConstructorMaxGrade();
	testBureaucratConstructorBelowMinGrade();
	testBureaucratConstructorAboveMaxGrade();
	testBureaucratInsertionOperator();

	return 0;
}