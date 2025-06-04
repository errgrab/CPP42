#include "./Bureaucrat.hpp"
#include "./Form.hpp"
#include <exception>
#include <iostream>

void testForm() {
	std::cout << "Test: form creation with grade too high." << std::endl;
	try {
		Form invalidForm("InvalidForm", 0, 50);
	} catch (std::exception &e) {
		std::cout << "Err: " << e.what() << std::endl;
	}

	std::cout << "Test: form creation with grade too low." << std::endl;
	try {
		Form invalidForm("InvalidForm", 151, 50);
	} catch (std::exception &e) {
		std::cout << "Err: " << e.what() << std::endl;
	}

	std::cout << "Test: form creation with valid grades." << std::endl;
	try {
		Form validForm("ValidForm", 50, 100);
		std::cout << validForm << std::endl;
	} catch (std::exception &e) {
		std::cout << "Err: " << e.what() << std::endl;
	}

		std::cout << "Test: signing with Bureaucrat grade higher (worse) than required." << std::endl;
	try {
		Bureaucrat b1("@.@", 76);
		Form f1("Form1", 75, 100);
		std::cout << b1 << std::endl;
		std::cout << f1 << std::endl;
		b1.signForm(f1); 
		std::cout << f1 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Err: " << e.what() << std::endl;
	}

	std::cout << "Test: signing with Bureaucrat grade equal to required." << std::endl;
	try {
		Bureaucrat b2(">.>", 100);
		Form f2("Form2", 100, 50);
		std::cout << b2 << std::endl;
		std::cout << f2 << std::endl;
		b2.signForm(f2); 
		std::cout << f2 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Err: " << e.what() << std::endl;
	}

	std::cout << "Test: signing with Bureaucrat grade lower (better) than required." << std::endl;
	try {
		Bureaucrat b3("e.e", 25);
		Form f3("Form3", 30, 30);
		std::cout << b3 << std::endl;
		std::cout << f3 << std::endl;
		b3.signForm(f3); 
		std::cout << f3 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Err: " << e.what() << std::endl;
	}
}

int main(void) {
	testForm();
	return (0);
}
