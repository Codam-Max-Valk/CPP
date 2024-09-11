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

class Span{
	private:
		unsigned int _n;
		std::vector<int> _vec;
	public:
		Span();
		Span(Span &other);
		Span &operator=(Span &other);
		Span(unsigned int n);
		~Span();
		void addNumber(int n);
		unsigned int shortestSpan();
		unsigned int longestSpan();
};
