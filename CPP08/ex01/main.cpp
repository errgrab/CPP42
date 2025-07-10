#include "Span.hpp"
#include <iostream>

int main(void) {
	Span sp;

	std::cout << "Example of subject, should print 2, 14" << std::endl;
	try {
		sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << ", " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Try the same thing without adding numbers, "
		<< "should print error." << std::endl;
	try {
		sp = Span(5);
		std::cout << sp.shortestSpan() << ", " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Try the same thing with only one number, "
		<< "should print error." << std::endl;
	try {
		sp = Span(5);
		sp.addNumber(0);
		std::cout << sp.shortestSpan() << ", " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Using iterators to make the same test, "
		<< "should print: 2, 14." << std::endl;
	try {
		sp = Span(5);
		int subjectArray[5] = { 6, 3, 17, 9, 11 };
		sp.addRange(&subjectArray[0], &subjectArray[5]);
		std::cout << sp.shortestSpan() << ", " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
