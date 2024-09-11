#pragma once

#include "Bureaucrat.hpp"

class FormNotSignedException : public std::exception{
	private:
		const char *_msg = "Form is not signed";
	public:
		const char *what() const noexcept;
};

class AForm{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;
	protected:
		AForm();
		AForm(std::string name, int signGrade, int execGrade);
		AForm(AForm const &other);
		AForm &operator=(AForm const &other);
	public:
		virtual ~AForm();
		const std::string getName() const;
		void beSigned(Bureaucrat &bureaucrat);
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		virtual void execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public ::GradeTooHighException {};
		class GradeTooLowException : public ::GradeTooLowException {};
		class FormNotSignedException : public ::FormNotSignedException {};
};

std::ostream &operator<<(std::ostream &out, const AForm &Aform);
