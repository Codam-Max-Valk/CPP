#pragma once

#include "AForm.hpp"
#include <fstream>
#include <ostream>

class ShrubberyCreationForm : public AForm{
	private:
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &other);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
		~ShrubberyCreationForm();
		void execute(Bureaucrat const &executor) const;
};
