#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), target(other.target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

const std::string& PresidentialPardonForm::getTarget() const {
	return target;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	try {
		if (!this->getIsSigned())
			throw AForm::FormNotSignedException();

		if (executor.getGrade() > this->getExecGrade())
			throw AForm::GradeTooLowException();

		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	} catch (const std::exception &e) {
		std::cerr << executor.getName() << " could not execute form "
			<< this->getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form) {
	os << "PresidentialPardonForm: " << form.getName() 
		<< ", Target: " << form.getTarget() 
		<< ", Signed: " << (form.getIsSigned() ? "Yes" : "No") 
		<< ", Sign Grade: " << form.getSignGrade() 
		<< ", Exec Grade: " << form.getExecGrade();
	return os;
}
