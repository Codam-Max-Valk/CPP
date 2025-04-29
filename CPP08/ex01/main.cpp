#include "Span.hpp"
#include <cstdint>
#include <cstdlib>
#include <ctime>

void	testSpanBasic() {
	Span span(5);

	// Test adding elements
	span.addNumber(10);
	span.addNumber(20);
	span.addNumber(30);
	span.addNumber(40);
	span.addNumber(50);

	// Test getting the shortest span
	int shortestSpan = span.shortestSpan();
	std::cout << "Shortest span: " << shortestSpan << std::endl;

	// Test getting the longest span
	int longestSpan = span.longestSpan();
	std::cout << "Longest span: " << longestSpan << std::endl;
}

void testSpanFull() {
	try {
		Span span(2);
		span.addNumber(10);
		span.addNumber(20);
		span.addNumber(30); // This should throw an exception
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testNotEnoughNumbers() {
	try {
		Span span(3);
		span.addNumber(10);
		span.shortestSpan(); // This should throw a NotEnoughNumbers exception
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Span span(1);
		span.addNumber(20);
		span.longestSpan(); // This should throw a NotEnoughNumbers exception
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testSpanFill() {
	Span span(10000);
	for (int i = 1; i <= 10000; i++) {
		span.addNumber(i);
	}
	int shortestSpan = span.shortestSpan();
	std::cout << "Shortest span: " << shortestSpan << std::endl;
	int longestSpan = span.longestSpan();
	std::cout << "Longest span: " << longestSpan << std::endl;
}

void testSpanRandom() {
	Span span(10001);
	for (int i = 0; i < 10001; i++) {
		int randomNumber = std::rand();
		span.addNumber(randomNumber);
	}
	int shortestSpan = span.shortestSpan();
	std::cout << "Shortest span: " << shortestSpan << std::endl;
	int longestSpan = span.longestSpan();
	std::cout << "Longest span: " << longestSpan << std::endl;
}

void testSpanMaxInt() {
	Span span(INT16_MAX);
	for (int i = 1; i <= INT16_MAX; i++) {
		span.addNumber(i);
	}
	int shortestSpan = span.shortestSpan();
	std::cout << "Shortest span: " << shortestSpan << std::endl;
	int longestSpan = span.longestSpan();
	std::cout << "Longest span: " << longestSpan << std::endl;
}

void testRange() {
	Span span(10);
	std::vector<int> numbers = {1, 2, 3, 4, 5};
	span.addRange(numbers.begin(), numbers.end());
	int shortestSpan = span.shortestSpan();
	std::cout << "Shortest span: " << shortestSpan << std::endl;
	int longestSpan = span.longestSpan();
	std::cout << "Longest span: " << longestSpan << std::endl;
}

int main() {
	std::srand(time(NULL));
	testSpanBasic();
	testSpanFull();
	testNotEnoughNumbers();
	testSpanFill();
	testSpanRandom();
	testSpanMaxInt();
	testRange();

	return 0;
}
