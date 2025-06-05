#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}
Intern::~Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    const std::string formTypes[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* forms[3] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };

    AForm* result = nullptr;
    for (int i = 0; i < 3; i++) {
        if (formName == formTypes[i]) {
            result = forms[i];
            std::cout << "Intern creates " << formName << std::endl;
        } else {
            delete forms[i];
        }
    }

    if (!result) {
        throw FormNotFoundException();
    }

    return result;
}

const char* Intern::FormNotFoundException::what() const throw() {
    return "Form type not found";
}
