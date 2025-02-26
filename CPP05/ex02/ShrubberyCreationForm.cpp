#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {
	if (DEBUG)
		std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137) {
	if (DEBUG)
		std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other) {
	if (DEBUG)
		std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other)
		AForm::operator=(other);
	if (DEBUG)
		std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	if (DEBUG)
		std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void	copyBush(std::string dest) {
	std::ifstream srcFile("bush.txt");
	std::ofstream destFile(dest);

	if (!srcFile.is_open() || !destFile.is_open())
		throw std::runtime_error("Error: Could not open the file.");
	
	destFile << srcFile.rdbuf();
	srcFile.close();
	destFile.close();
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const{
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();

	copyBush(getName() + "_shrubbery");
	std::cout << "Bush printed in 'shrubbery' file." << std::endl;
}
