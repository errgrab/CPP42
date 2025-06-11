#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>
#include <iostream>

void testIntern() {
	Intern intern;
	AForm *form;

	std::cout << "Testing Shrubbery Form Creation:" << std::endl;
	try {
		form = intern.makeForm("shrubbery creation", "home");
		std::cout << *form << std::endl;
		delete form;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Testing Robotomy Request Form Creation:" << std::endl;
	try {
		form = intern.makeForm("robotomy request", "Bender");
		std::cout << *form << std::endl;
		delete form;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Testing Presidential Pardon Form Creation:" << std::endl;
	try {
		form = intern.makeForm("presidential pardon", "Fry");
		std::cout << *form << std::endl;
		delete form;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Testing Unknown Form Creation:" << std::endl;
	try {
		form = intern.makeForm("unknown form", "Unknown");
		std::cout << *form << std::endl;
		delete form;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int main(void) {
	testIntern();
	return (0);
}
