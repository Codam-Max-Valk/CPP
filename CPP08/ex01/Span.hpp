#pragma once

#include <algorithm>
#include <iostream>
#include <exception>
#include <vector>

class NotEnoughNumbers : public std::exception{
	private:
		std::string _msg = "Not enough numbers in Span";
	public:
		const char *what() const noexcept{
			return _msg.c_str();
		}
};

class SpanFull : public std::exception{
	private:
		std::string _msg = "Span is full";
	public:
		const char *what() const noexcept{
			return _msg.c_str();
		}
};

class Span {
	private:
		unsigned int _n;
		std::vector<int> _vec;
		Span();
	public:
		Span(unsigned int n);
		Span(Span &other);
		Span &operator=(Span &other);
		~Span();
		void addNumber(int n);
		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		unsigned int shortestSpan();
		unsigned int longestSpan();
};
