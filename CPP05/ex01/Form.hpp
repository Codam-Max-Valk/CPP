#pragma once

#include "Bureaucrat.hpp"

class Form{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;
		Form();
	public:
		Form(std::string name, int signGrade, int execGrade);
		Form(Form const &other);
		Form &operator=(Form const &other);
		~Form();
		const std::string getName() const;
		void beSigned(Bureaucrat &bureaucrat);
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		class GradeTooHighException : public ::GradeTooHighException {};
		class GradeTooLowException : public ::GradeTooLowException {};
};

std::ostream &operator<<(std::ostream &out, const Form &form);
