#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

PresidentialPardonForm::PresidentialPardonForm() {
	if (DEBUG)
		std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5) {
	if (DEBUG)
		std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other) {
	if (DEBUG)
		std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other)
		AForm::operator=(other);
	if (DEBUG)
		std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	if (DEBUG)
		std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const{
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	std::cout << getName() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
