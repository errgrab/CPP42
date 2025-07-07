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

	return 0;
}
