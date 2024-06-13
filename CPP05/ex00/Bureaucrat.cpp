#include "Bureaucrat.hpp"
#include <cstring>
#include <ostream>

const char *Bureaucrat::GradeTooHighException::what() const noexcept{
	return _msg;
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept{
	return _msg;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat){
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return out;
}

Bureaucrat::Bureaucrat(){
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade){
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other){
	if (this != &other)
	{
		const_cast<std::string&>(_name) = other._name;
		_grade = other._grade;
	}
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	return *this;
}

const std::string Bureaucrat::getName() const{
	return _name;
}

int Bureaucrat::getGrade() const{
	return _grade;
}

void Bureaucrat::incrementGrade(){
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade(){
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}


