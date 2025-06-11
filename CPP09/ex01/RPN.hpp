#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <exception>

#define OPERATORS "+-*/"

class InvalidExpressionException : public std::exception {
	private:
		std::string _msg;
	public:
		InvalidExpressionException(const std::string &context) : _msg("Invalid expression: " + context) {}
		const char *what() const noexcept override { return _msg.c_str(); }
};

class RPN {
	private:
		std::stack<int> operands;
		std::string _operators = OPERATORS;
		int result = 0;
		void performOperation(char op);
	public:
		RPN() = default;
		RPN(const RPN &copy) = delete;
		RPN &operator=(const RPN &copy) = delete;
		~RPN() = default;

		void evaluate(const std::string &expression);
		int getResult() const;
};