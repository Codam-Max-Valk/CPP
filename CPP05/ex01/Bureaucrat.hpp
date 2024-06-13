#pragma once

#include <iostream>
#include <ostream>
#include <string>
#include "Exceptions.hpp"

class Bureaucrat{
	private:
		const std::string _name;
		int _grade;
		Bureaucrat();

	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat &operator=(Bureaucrat const &other);
		~Bureaucrat();
		const std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();


		class GradeTooHighException : public ::GradeTooHighException {};
		class GradeTooLowException : public ::GradeTooLowException {};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
