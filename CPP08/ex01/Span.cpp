#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <vector>

Span::Span() : _n(0) {};

Span::Span(Span &other) : _n(other._n), _vec(other._vec) {};

Span::Span(unsigned int n) : _n(n) {};

Span::~Span() {};

Span &Span::operator=(Span &other) {
	_n = other._n;
	_vec = other._vec;
	return *this;
}

void Span::addNumber(int n) {
	if (_vec.size() == _n)
		throw SpanFull();
	_vec.push_back(n);
}

unsigned int Span::longestSpan() {
	if (_n < 2)
		throw NotEnoughNumbers();
	int minElement = *std::min_element(_vec.begin(), _vec.end());
	int maxElement = *std::max_element(_vec.begin(), _vec.end());

	return maxElement - minElement;
}

unsigned int Span::shortestSpan() {
	if (_n < 2)
		throw NotEnoughNumbers();
	std::vector<int> &vecCopy = _vec;
	std::sort(vecCopy.begin(), vecCopy.end());

	unsigned int shortestSpan = std::numeric_limits<int>::max();
	for (unsigned int i = 1; i < _n; i++) {
		unsigned int span = vecCopy[i] - vecCopy[i - 1];
		if (span < shortestSpan)
			shortestSpan = span;
	}
	return shortestSpan;
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (std::distance(begin, end) + _vec.size() > _n)
		throw SpanFull();
	_vec.insert(_vec.end(), begin, end);
}
