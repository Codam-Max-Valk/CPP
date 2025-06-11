#include "RPN.hpp"

int RPN::getResult() const {
	return result;
}

void RPN::performOperation(char op) {
	if (operands.size() < 2) {
		throw InvalidExpressionException("Error: Not enough operands for operation");
	}
	int b = operands.top();
	operands.pop();
	int a = operands.top();
	operands.pop();
	switch (op) {
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			if (b == 0) {
				throw InvalidExpressionException("Error: Division by zero");
			}
			result = a / b;
			break;
		default:
			throw InvalidExpressionException("Error: Unknown operator: " + std::string(1, op));
	}
	operands.push(result);
}

void RPN::evaluate(const std::string &expression) {
	std::istringstream iss(expression);
	std::string token;
	while (iss >> token) {
		if (token.length() == 1 && _operators.find(token[0]) != std::string::npos) {
			performOperation(token[0]);
		} else {
			try {
				int operand = std::stoi(token);
				operands.push(operand);
			} catch (const std::invalid_argument &) {
				throw InvalidExpressionException("Error: Invalid operand: " + token);
			} catch (const std::out_of_range &) {
				throw InvalidExpressionException("Error: Operand out of range: " + token);
			}
		}
	}
	if (operands.size() != 1) {
		throw InvalidExpressionException("Error: Invalid expression: too many operands left");
	}
	result = operands.top();
}
