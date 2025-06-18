#include <cassert>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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

// Test case 7: Creating a Form with a valid grade
void testFormConstructorValidGrade() {
	Form f("Form 1", 50, 75);
	std::cout << "Name: " << f.getName() << ", Sign grade: " << f.getSignGrade() << ", Execute grade: " << f.getExecGrade() << std::endl;
	assert(f.getName() == "Form 1");
	assert(f.getSignGrade() == 50);
	assert(f.getExecGrade() == 75);
	std::cout << "Test case 7: Form with valid grade - [OK]" << std::endl;
}

// Test case 8: Creating a Form with the minimum grade
void testFormConstructorMinGrade() {
	Form f("Form 2", 1, 1);
	std::cout << "Name: " << f.getName() << ", Sign grade: " << f.getSignGrade() << ", Execute grade: " << f.getExecGrade() << std::endl;
	assert(f.getName() == "Form 2");
	assert(f.getSignGrade() == 1);
	assert(f.getExecGrade() == 1);
	std::cout << "Test case 8: Form with minimum grade - [OK]" << std::endl;
}

// Test case 9: Creating a Form with the maximum grade
void testFormConstructorMaxGrade() {
	Form f("Form 3", 150, 150);
	std::cout << "Name: " << f.getName() << ", Sign grade: " << f.getSignGrade() << ", Execute grade: " << f.getExecGrade() << std::endl;
	assert(f.getName() == "Form 3");
	assert(f.getSignGrade() == 150);
	assert(f.getExecGrade() == 150);
	std::cout << "Test case 9: Form with maximum grade - [OK]" << std::endl;
}

// Test case 10: Creating a Form with a grade below the minimum
void testFormConstructorBelowMinGrade() {
	try {
		Form f("Form 4", 0, 75);
		// The constructor should throw an exception, so this line should not be reached
		assert(false);
	} catch (std::exception &e) {
		std::cout << "Exception thrown: " << e.what() << std::endl;
		assert(std::string(e.what()) == "Grade is too high");
		std::cout << "Test case 10: Form with grade below minimum - [OK]" << std::endl;
	}
}

// Test case 11: Creating a Form with a grade above the maximum
void testFormConstructorAboveMaxGrade() {
	try {
		Form f("Form 5", 151, 75);
		// The constructor should throw an exception, so this line should not be reached
		assert(false);
	} catch (std::exception &e) {
		std::cout << "Exception thrown: " << e.what() << std::endl;
		assert(std::string(e.what()) == "Grade is too low");
		std::cout << "Test case 11: Form with grade above maximum - [OK]" << std::endl;
	}
}

// Test case 12: Signing a Form with a Bureaucrat with enough grade
void testFormSignWithEnoughGrade() {
	Bureaucrat b("John Doe", 50);
	Form f("Form 6", 50, 75);
	// f.beSigned(b);
	b.signForm(f);
	std::cout << f;
	std::cout << "Test case 12: Signing a Form with enough grade - [OK]" << std::endl;
}

// Test case 13: Signing a Form with a Bureaucrat with not enough grade
void testFormSignWithNotEnoughGrade() {
	Bureaucrat b("Jane Smith", 75);
	Form f("Form 7", 50, 75);
	try {
		f.beSigned(b);
		// The beSigned function should throw an exception, so this line should not be reached
		assert(false);
	} catch (std::exception &e) {
		std::cout << "Exception thrown: " << e.what() << std::endl;
		assert(std::string(e.what()) == "Grade is too low");
		std::cout << "Test case 13: Signing a Form with not enough grade - [OK]" << std::endl;
	}
}

//-----------------------------------------------------------------------------------------------
 #include <sstream>
// Test case 14: Signing a Form with a Bureaucrat with enough grade
void testBureaucratSignFormWithEnoughGrade() {
	Bureaucrat b("John Doe", 50);
	Form f("Form 8", 50, 75);
	std::stringstream ss;
	std::streambuf* prevCoutBuf = std::cout.rdbuf(ss.rdbuf());

	b.signForm(f);
	std::cout.rdbuf(prevCoutBuf);
	std::string expectedOutput = b.getName() + " signed " + f.getName() + "\n";
	assert(ss.str() == expectedOutput);
	std::cout << b;
	std::cout << f;
	std::cout << ss.str();
}

// Test case 15: Signing a Form with a Bureaucrat with not enough grade
void testBureaucratSignFormWithNotEnoughGrade() {
	Bureaucrat b("John Doe", 50);
	Form f("Form 9", 40, 75);
	std::stringstream ss;
	std::streambuf* prevCoutBuf = std::cout.rdbuf(ss.rdbuf());

	b.signForm(f);

	std::cout.rdbuf(prevCoutBuf);
	std::string expectedOutput = b.getName() + " couldn't sign " + f.getName() + \
		" because Grade is too low" + "\n";
	assert(ss.str() == expectedOutput);
	std::cout << b;
	std::cout << f;
	std::cout << ss.str();
}
//-----------------------------------------------------------------------------------------------

int main() {
	testBureaucratConstructorValidGrade();
	std::cout << "------------------------" << std::endl;
	testBureaucratConstructorMinGrade();
	std::cout << "------------------------" << std::endl;
	testBureaucratConstructorMaxGrade();
	std::cout << "------------------------" << std::endl;
	testBureaucratConstructorBelowMinGrade();
	std::cout << "------------------------" << std::endl;
	testBureaucratConstructorAboveMaxGrade();
	std::cout << "------------------------" << std::endl;
	testBureaucratInsertionOperator();
	std::cout << "------------------------" << std::endl;
	testFormConstructorValidGrade();
	std::cout << "------------------------" << std::endl;
	testFormConstructorMinGrade();
	std::cout << "------------------------" << std::endl;
	testFormConstructorMaxGrade();
	std::cout << "------------------------" << std::endl;
	testFormConstructorBelowMinGrade();
	std::cout << "------------------------" << std::endl;
	testFormConstructorAboveMaxGrade();
	std::cout << "------------------------" << std::endl;
	testFormSignWithEnoughGrade();
	std::cout << "------------------------" << std::endl;
	testFormSignWithNotEnoughGrade();
	std::cout << "------------------------" << std::endl;
	testBureaucratSignFormWithEnoughGrade();
	std::cout << "------------------------" << std::endl;
	testBureaucratSignFormWithNotEnoughGrade();
	return 0;
}