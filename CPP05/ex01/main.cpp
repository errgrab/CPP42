#include "./Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main(void) {
	try {
		Bureaucrat high("Alice", 1);
		std::cout << high << std::endl;
		high.incrementGrade();
	} catch (std::exception &e) {
		std::cout << "Err: " << e.what() << std::endl;
	}
	try {
		Bureaucrat low("Jorge", 150);
		std::cout << low << std::endl;
		low.decrementGrade();
	} catch (std::exception &e) {
		std::cout << "Err: " << e.what() << std::endl;
	}
	try {
		Bureaucrat invalid("Aw<", 0);
	} catch (std::exception &e) {
		std::cout << "Err: " << e.what() << std::endl;
	}
	return (0);
}
