#include <cassert>
#include <exception>
#include <iostream>
#include <unistd.h>
#include <ctime>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	NoShrubberyCreationFormSign(){
	try {
		Bureaucrat crat("John Doe", 1);
		ShrubberyCreationForm form("garden");
		form.execute(crat);

		assert(false);
	}
	catch (std::exception &e){
		std::cout << "Exception thrown: " << e.what() << std::endl;
		assert(std::string(e.what()) == "Form is not signed");
		std::cout << "Test case 1: ShrubberyCreationForm not signed - [OK]" << std::endl;
	}
}

void	NoRobotomyRequestFormSign(){
	try {
		Bureaucrat crat("John Doe", 1);
		RobotomyRequestForm form("robot");
		form.execute(crat);

		assert(false);
	}
	catch (std::exception &e){
		std::cout << "Exception thrown: " << e.what() << std::endl;
		assert(std::string(e.what()) == "Form is not signed");
		std::cout << "Test case 1: RobotomyRequestForm not signed - [OK]" << std::endl;
	}
}

void	NoPresidentialPardonFormSign(){
	try {
		Bureaucrat crat("John Doe", 1);
		PresidentialPardonForm form("criminal");
		form.execute(crat);

		assert(false);
	}
	catch (std::exception &e){
		std::cout << "Exception thrown: " << e.what() << std::endl;
		assert(std::string(e.what()) == "Form is not signed");
		std::cout << "Test case 1: PresidentialPardonForm not signed - [OK]" << std::endl;
	}
}

void	NoShrubberyCreationFormGrade(){
	try {
		Bureaucrat crat("John Doe", 150);
		ShrubberyCreationForm form("garden");
		form.beSigned(crat);
		form.execute(crat);

		assert(false);
	}
	catch (std::exception &e){
		std::cout << "Exception thrown: " << e.what() << std::endl;
		assert(std::string(e.what()) == "Grade is too low");
		std::cout << "Test case 1: ShrubberyCreationForm grade too low - [OK]" << std::endl;
	}
}

void	NoRobotomyRequestFormGrade(){
	try {
		Bureaucrat crat("John Doe", 150);
		RobotomyRequestForm form("robot");
		form.beSigned(crat);
		form.execute(crat);

		assert(false);
	}
	catch (std::exception &e){
		std::cout << "Exception thrown: " << e.what() << std::endl;
		assert(std::string(e.what()) == "Grade is too low");
		std::cout << "Test case 1: RobotomyRequestForm grade too low - [OK]" << std::endl;
	}
}

void	NoPresidentialPardonFormGrade(){
	try {
		Bureaucrat crat("John Doe", 150);
		PresidentialPardonForm form("criminal");
		form.beSigned(crat);
		form.execute(crat);

		assert(false);
	}
	catch (std::exception &e){
		std::cout << "Exception thrown: " << e.what() << std::endl;
		assert(std::string(e.what()) == "Grade is too low");
		std::cout << "Test case 1: PresidentialPardonForm grade too low - [OK]" << std::endl;
	}
}



// Test cases for ShrubberyCreationForm
void	testShrubberyCreationForm()
{
	Bureaucrat crat("John Doe", 1);
	ShrubberyCreationForm form("garden");

	form.beSigned(crat);
	form.execute(crat);

	assert(form.getSigned());

	std::ifstream file("garden_shrubbery");
	assert(file.good());
	std::string line;
	while (std::getline(file, line)) {
		std::cout << line << std::endl;
	}
	file.close();
	unlink("garden_shrubbery");
}

// Test cases for RobotomyRequestForm
void	testRobotomyRequestForm()
{
	Bureaucrat bureaucrat("Jane Smith", 1);
	RobotomyRequestForm form("robot");

	// Test execution of the form
	form.beSigned(bureaucrat);
	form.execute(bureaucrat);

	// Test if the form is signed after execution
	assert(form.getSigned());
}

// Test cases for PresidentialPardonForm
void	testPresidentialPardonForm()
{
	Bureaucrat bureaucrat("Mike Johnson", 5);
	PresidentialPardonForm form("criminal");

	// Test execution of the form
	form.beSigned(bureaucrat);
	form.execute(bureaucrat);

	// Test if the form is signed after execution
	assert(form.getSigned());
}


int	main()
{
	srand(time(0));
	std::cout << "------------------------------------" << std::endl;
	NoShrubberyCreationFormSign();
	std::cout << "------------------------------------" << std::endl;
	NoPresidentialPardonFormSign();
	std::cout << "------------------------------------" << std::endl;
	NoRobotomyRequestFormSign();
	std::cout << "------------------------------------" << std::endl;
	NoShrubberyCreationFormGrade();
	std::cout << "------------------------------------" << std::endl;
	NoRobotomyRequestFormGrade();
	std::cout << "------------------------------------" << std::endl;
	testShrubberyCreationForm();
	std::cout << "------------------------------------" << std::endl;
	testRobotomyRequestForm();
	std::cout << "------------------------------------" << std::endl;
	testPresidentialPardonForm();
	std::cout << "------------------------------------" << std::endl;
	return 0;
}
