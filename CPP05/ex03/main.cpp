#include <cassert>
#include <exception>
#include <iostream>
#include <unistd.h>
#include <ctime>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	ShrubberyCreationFormNoSign() {
	try {
		Bureaucrat crat("John Doe", 1);
		ShrubberyCreationForm form("garden");
		form.execute(crat);

		assert(false);
	}
	catch (std::exception &e) {
		std::cout << "Exception thrown: " << e.what() << std::endl;
		assert(std::string(e.what()) == "Form is not signed");
		std::cout << "Test case 1: ShrubberyCreationForm not signed - [OK]" << std::endl;
	}
}

void	ShrubberyCreationFormNoGrade() {
	try {
		Bureaucrat crat("John Doe", 150);
		ShrubberyCreationForm form("garden");
		form.beSigned(crat);
		form.execute(crat);

		assert(false);
	}
	catch (std::exception &e) {
		std::cout << "Exception thrown: " << e.what() << std::endl;
		assert(std::string(e.what()) == "Grade is too low");
		std::cout << "Test case 1: ShrubberyCreationForm grade too low - [OK]" << std::endl;
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

void	RobotomyRequestFormNoSign() {
	Bureaucrat crat("John Doe", 1);
	RobotomyRequestForm form("robot");
	try {
		form.execute(crat);

		assert(false);
	}
	catch (std::exception &e) {
		std::cout << form;
		std::cout << "Exception thrown: " << e.what() << std::endl;
		assert(std::string(e.what()) == "Form is not signed");
		std::cout << "Test case 1: RobotomyRequestForm not signed - [OK]" << std::endl;
	}
}

void	RobotomyRequestFormNoGrade() {
	Bureaucrat crat("John Doe", 150);
	RobotomyRequestForm form("robot");
	try {
		form.beSigned(crat);
		form.execute(crat);

		assert(false);
	}
	catch (std::exception &e) {
		std::cout << form;
		std::cout << "Exception thrown: " << e.what() << std::endl;
		assert(std::string(e.what()) == "Grade is too low");
		std::cout << "Test case 1: RobotomyRequestForm grade too low - [OK]" << std::endl;
	}
}

void	PresidentialPardonFormNoSign() {
	Bureaucrat crat("John Doe", 1);
	PresidentialPardonForm form("criminal");
	try {
		form.execute(crat);

		assert(false);
	}
	catch (std::exception &e) {
		std::cout << form;
		std::cout << "Exception thrown: " << e.what() << std::endl;
		assert(std::string(e.what()) == "Form is not signed");
		std::cout << "Test case 1: PresidentialPardonForm not signed - [OK]" << std::endl;
	}
}

void	PresidentialPardonFormNoGrade() {
	Bureaucrat crat("John Doe", 150);
	PresidentialPardonForm form("criminal");
	try {
		form.beSigned(crat);
		form.execute(crat);

		assert(false);
	}
	catch (std::exception &e) {
		std::cout << form;
		std::cout << "Exception thrown: " << e.what() << std::endl;
		assert(std::string(e.what()) == "Grade is too low");
		std::cout << "Test case 1: PresidentialPardonForm grade too low - [OK]" << std::endl;
	}
}

// Test cases for RobotomyRequestForm
void	testRobotomyRequestForm()
{
	Bureaucrat bureaucrat("Jane Smith", 1);
	RobotomyRequestForm form("Joe Biden");

	form.beSigned(bureaucrat);
	for (int i = 0; i < 10; i++) {
		form.execute(bureaucrat);
	}
}

// Test cases for PresidentialPardonForm
void	testPresidentialPardonForm()
{
	Bureaucrat bureaucrat("Joseph Robinette Biden jr.", 5);
	PresidentialPardonForm form("Donald John Trump");

	form.beSigned(bureaucrat);
	form.execute(bureaucrat);

	assert(form.getSigned());
}


int	main()
{
	AForm *Form;
	Intern intern;

	srand(time(0));
	// std::cout << "------------------------------------" << std::endl;
	// ShrubberyCreationFormNoSign();
	// std::cout << "------------------------------------" << std::endl;
	// PresidentialPardonFormNoSign();
	// std::cout << "------------------------------------" << std::endl;
	// RobotomyRequestFormNoSign();
	// std::cout << "------------------------------------" << std::endl;
	// ShrubberyCreationFormNoGrade();
	// std::cout << "------------------------------------" << std::endl;
	// RobotomyRequestFormNoGrade();
	// std::cout << "------------------------------------" << std::endl;
	// PresidentialPardonFormNoGrade();
	// std::cout << "------------------------------------" << std::endl;
	// testShrubberyCreationForm();
	// std::cout << "------------------------------------" << std::endl;
	// testRobotomyRequestForm();
	// std::cout << "------------------------------------" << std::endl;
	// testPresidentialPardonForm();
	// std::cout << "------------------------------------" << std::endl;

	Form = intern.makeForm("shrubbery creation", "BIG BRO");
	std::cout << "------------------------------------" << std::endl;
	std::cout << *Form;
	delete Form;
	std::cout << "------------------------------------" << std::endl;
	Form = intern.makeForm("robotomy request", "LIL BRO");
	std::cout << "------------------------------------" << std::endl;
	std::cout << *Form;
	delete Form;
	std::cout << "------------------------------------" << std::endl;
	Form = intern.makeForm("presidential pardon", "BIG SIS");
	std::cout << "------------------------------------" << std::endl;
	std::cout << *Form;
	delete Form;
	std::cout << "------------------------------------" << std::endl;
	Form = intern.makeForm("fake form", "Crowdstrike");
	std::cout << "------------------------------------" << std::endl;
	// std::cout << Form;
	delete Form;
	std::cout << "------------------------------------" << std::endl;
	return 0;
}
