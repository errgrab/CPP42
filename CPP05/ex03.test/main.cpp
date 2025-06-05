#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

void testShrubberyCreationForm() {
	std::cout << "Testing ShrubberyCreationForm" << std::endl;
	try {
		Bureaucrat highGrade("HighGrade", 1);
		Bureaucrat lowGrade("LowGrade", 150);
		ShrubberyCreationForm form("garden");

		std::cout << form << std::endl;
		std::cout << highGrade << std::endl;
		std::cout << lowGrade << std::endl;

		// Test signing with low grade
		lowGrade.signForm(form);

		// Test signing with high grade
		highGrade.signForm(form);

		// Test executing with low grade
		lowGrade.executeForm(form);

		// Test executing with high grade
		highGrade.executeForm(form);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testRobotomyRequestForm() {
	std::cout << "Testing RobotomyRequestForm" << std::endl;
	try {
		Bureaucrat highGrade("HighGrade", 1);
		Bureaucrat midGrade("MidGrade", 50);
		RobotomyRequestForm form("target");

		std::cout << form << std::endl;
		std::cout << highGrade << std::endl;
		std::cout << midGrade << std::endl;

		// Test signing with mid grade
		midGrade.signForm(form);

		// Test signing with high grade
		highGrade.signForm(form);

		// Test multiple executions to see randomization
		for (int i = 0; i < 5; i++) {
			highGrade.executeForm(form);
		}
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testPresidentialPardonForm() {
	std::cout << "Testing PresidentialPardonForm" << std::endl;
	try {
		Bureaucrat highGrade("HighGrade", 1);
		Bureaucrat midGrade("MidGrade", 20);
		PresidentialPardonForm form("criminal");

		std::cout << form << std::endl;
		std::cout << highGrade << std::endl;
		std::cout << midGrade << std::endl;

		// Test executing without signing
		highGrade.executeForm(form);

		// Test signing and executing
		highGrade.signForm(form);
		highGrade.executeForm(form);

		// Test executing with mid grade
		midGrade.executeForm(form);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testIntern() {
	std::cout << "\nTesting Intern" << std::endl;
	
	Intern someRandomIntern;
	Bureaucrat boss("Boss", 1);
	AForm* rrf;
	
	try {
		// Test creating a valid form
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
		
		// Test creating another valid form
		AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Home");
		std::cout << *scf << std::endl;
		boss.signForm(*scf);
		boss.executeForm(*scf);
		delete scf;
		
		// Test creating another valid form
		AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Criminal");
		std::cout << *ppf << std::endl;
		boss.signForm(*ppf);
		boss.executeForm(*ppf);
		delete ppf;
		
		// Test creating an invalid form
		AForm* invalidForm = someRandomIntern.makeForm("invalid form", "Target");
		delete invalidForm; // This should not be executed
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

int main() {
	testShrubberyCreationForm();
	testRobotomyRequestForm();
	testPresidentialPardonForm();
	testIntern();
	return 0;
}
