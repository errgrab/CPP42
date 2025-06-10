#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>
#include <iostream>

void testShrubberyCreationForm() {
	ShrubberyCreationForm form("Home");
	Bureaucrat bureaucrat("Alice", 137);
	
	try {
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void testRobotomyRequestForm() {
	RobotomyRequestForm form("Robot");
	Bureaucrat bureaucrat("Bob", 45);
	
	try {
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void testPresidentialPardonForm() {
	PresidentialPardonForm form("Target");
	Bureaucrat bureaucrat("Charlie", 5);
	
	try {
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

int main(void) {
	testShrubberyCreationForm();
	testRobotomyRequestForm();
	testPresidentialPardonForm();
	return (0);
}
