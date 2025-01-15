#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _signGrade(1), _execGrade(1){
	if (DEBUG)
		std::cout << "Form default constructor called" << std::endl;
}

Form::~Form(){
	if (DEBUG)
		std::cout << "Form destructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade){
	if (DEBUG)
		std::cout << "Form constructor called" << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade){
	if (DEBUG)
		std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(Form const &other){
	if (DEBUG)
		std::cout << "Form assignation operator called" << std::endl;
	if (this != &other)
	{
		const_cast<std::string&>(_name) = other._name;
		_signed = other._signed;
	}
	return *this;
}

const std::string Form::getName() const{
	return _name;
}

bool Form::getSigned() const{
	return _signed;
}

int Form::getSignGrade() const{
	return _signGrade;
}

int Form::getExecGrade() const{
	return _execGrade;
}

void Form::beSigned(Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	_signed = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form){
	out << "Form " << form.getName() << ", sign grade " << form.getSignGrade() << ", exec grade " << form.getExecGrade() << ", signed " << form.getSigned() << std::endl;
	return out;
}
