#include "AForm.hpp"

const char *FormNotSignedException::what() const noexcept {
	return _msg;
}

AForm::AForm() : _name("default"), _signed(false), _signGrade(1), _execGrade(1){
	if (DEBUG)
		std::cout << "AForm default constructor called" << std::endl;
}

AForm::~AForm(){
	if (DEBUG)
		std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade){
	if (DEBUG)
		std::cout << "AForm constructor called" << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade){
	if (DEBUG)
		std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &other){
	if (DEBUG)
		std::cout << "AForm assignation operator called" << std::endl;
	if (this != &other)
	{
		const_cast<std::string&>(_name) = other._name;
		_signed = other._signed;
	}
	return *this;
}

const std::string AForm::getName() const{
	return _name;
}

bool AForm::getSigned() const{
	return _signed;
}

int AForm::getSignGrade() const{
	return _signGrade;
}

int AForm::getExecGrade() const{
	return _execGrade;
}

void AForm::beSigned(Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm){
	out << "AForm " << AForm.getName() << ", sign grade " << AForm.getSignGrade() << ", exec grade " << AForm.getExecGrade() << ", signed " << AForm.getSigned() << std::endl;
	return out;
}
