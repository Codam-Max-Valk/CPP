#pragma once

#include <exception>

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
