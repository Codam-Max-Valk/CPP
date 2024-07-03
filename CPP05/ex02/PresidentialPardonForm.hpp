#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
	private:
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &other);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
		~PresidentialPardonForm();
		void execute(Bureaucrat const &executor) const;
};
