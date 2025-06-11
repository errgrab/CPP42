#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	(void)other;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
	const std::string formTypes[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm *result = NULL;

	for (int i = 0; i < 3; i++) {
		if (formName == formTypes[i]) {
			switch (i) {
				case 0:
					result = new ShrubberyCreationForm(target);
					break;
				case 1:
					result = new RobotomyRequestForm(target);
					break;
				case 2:
					result = new PresidentialPardonForm(target);
					break;
			}
			std::cout << "Intern creates " << formName << " form." << std::endl;
			break;
		}
	}

	if (!result) {
		throw FormNotFoundException();
	}

	return result;
}

const char *Intern::FormNotFoundException::what() const throw() {
	return "form type not found";
}
