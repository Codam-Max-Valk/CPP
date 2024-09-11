#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){
	if (DEBUG)
		std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &other){
	if (DEBUG)
		std::cout << "Intern copy constructor called" << std::endl;
	*this = other;
}

Intern &Intern::operator=(Intern const &other){
	if (this != &other)
		*this = other;
	if (DEBUG)
		std::cout << "Intern assignation operator called" << std::endl;
	return *this;
}

Intern::~Intern(){
	if (DEBUG)
		std::cout << "Intern destructor called" << std::endl;
}

AForm *createRobotomyRequestForm(std::string target){
	return new RobotomyRequestForm(target);
}

AForm *createPresidentialPardonForm(std::string target){
	return new PresidentialPardonForm(target);
}

AForm *createShrubberyCreationForm(std::string target){
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target){
	std::string FormNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*CreateForms[])(std::string) = {createShrubberyCreationForm, createRobotomyRequestForm, createPresidentialPardonForm};

	for (int i = 0; i < 3; i++){
		if (formName == FormNames[i]){
			std::cout << "Intern creates " << formName << std::endl;
			return CreateForms[i](target);
		}
	}
	std::cout << "ERROR ERROR: the intern has been fired because you gave it the wrong form name!" << std::endl;
	return NULL;
}
