#pragma once

#include <iostream>
#include <ostream>
#include <string>

<<<<<<< Updated upstream
#ifndef DEBUG
	#define DEBUG 0
#endif

=======
>>>>>>> Stashed changes
class GradeTooHighException : public std::exception{
	private:
		const char *_msg = "Grade is too high";
	public:
		const char *what() const noexcept;
};

class GradeTooLowException : public std::exception{
	private:
		const char *_msg = "Grade is too low";
	public:
		const char *what() const noexcept;
};

<<<<<<< Updated upstream
class Form;
=======
>>>>>>> Stashed changes

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
<<<<<<< Updated upstream
		void signForm(Form &form);
=======
		
>>>>>>> Stashed changes

		class GradeTooHighException : public ::GradeTooHighException {};
		class GradeTooLowException : public ::GradeTooLowException {};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
