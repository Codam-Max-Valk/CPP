#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <ostream>

RobotomyRequestForm::RobotomyRequestForm() {
	if (DEBUG)
		std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45) {
	if (DEBUG)
		std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other) {
	if (DEBUG)
		std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other)
		AForm::operator=(other);
	if (DEBUG)
		std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	if (DEBUG)
		std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const{
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	std::cout << "*INSERT DRILLING NOISE HERE*" << std::endl;
	
	if (!(rand() % 2))
		std::cout << getName() << " has been succesfully Robotomized" << std::endl;
	else
		std::cout << "The Robotomy on " << getName() << " has failed. BIG L for them" << std::endl;
}
