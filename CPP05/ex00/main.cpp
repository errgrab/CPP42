#include "./Bureaucrat.hpp"
#include <exception>
#include <iostream>

void testBureaucrat() {
	std::cout << "Test: grade increment beyond valid range (grade 1)." << std::endl;
	try {
		Bureaucrat high("HighRank", 1);
		std::cout << high << std::endl;
		high.incrementGrade();
	} catch (std::exception &e) {
		std::cout << "Err: " << e.what() << std::endl;
	}

	std::cout << "\nTest: grade decrement beyond valid range (grade 150)." << std::endl;
	try {
		Bureaucrat low("LowRank", 150);
		std::cout << low << std::endl;
		low.decrementGrade();
	} catch (std::exception &e) {
		std::cout << "Err: " << e.what() << std::endl;
	}

	std::cout << "\nTest: creating a Bureaucrat with grade 0." << std::endl;
	try {
		Bureaucrat invalid("AwA", 0);
	} catch (std::exception &e) {
		std::cout << "Err: " << e.what() << std::endl;
	}

	std::cout << "\nTest: creating a Bureaucrat with grade 151." << std::endl;
	try {
		Bureaucrat invalid("UwU", 151);
	} catch (std::exception &e) {
		std::cout << "Err: " << e.what() << std::endl;
	}

	std::cout << "\nTest: creating a Bureaucrat with grade 1." << std::endl;
	try {
		Bureaucrat valid("Valid", 1);
		std::cout << valid << std::endl;
	} catch (std::exception &e) {
		std::cout << "Err: " << e.what() << std::endl;
	}

	std::cout << "\nTest: creating a Bureaucrat with grade 150." << std::endl;
	try {
		Bureaucrat valid("ValidLow", 150);
		std::cout << valid << std::endl;
	} catch (std::exception &e) {
		std::cout << "Err: " << e.what() << std::endl;
	}

	std::cout << "\nTest: incrementing grade of a Bureaucrat with grade 75." << std::endl;
	try {
		Bureaucrat mid("Mid", 75);
		std::cout << mid << std::endl;
		mid.incrementGrade();
		std::cout << "After increment: " << mid << std::endl;
	} catch (std::exception &e) {
		std::cout << "Err: " << e.what() << std::endl;
	}

	std::cout << "\nTest: decrementing grade of a Bureaucrat with grade 75." << std::endl;
	try {
		Bureaucrat mid("Mid", 75);
		std::cout << mid << std::endl;
		mid.decrementGrade();
		std::cout << "After decrement: " << mid << std::endl;
	} catch (std::exception &e) {
		std::cout << "Err: " << e.what() << std::endl;
	}
}

int main(void) {
	testBureaucrat();
	return (0);
}
