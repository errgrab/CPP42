#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cmath>

AForm::AForm()
	: name("Default"), isSigned(false), signGrade(150), execGrade(150) {}

AForm::AForm(const std::string& name, int signGrade, int execGrade)
	: name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		isSigned = other.isSigned;
	}
	return *this;
}

const std::string& AForm::getName() const { return name; }

bool AForm::getIsSigned() const { return isSigned; }

int AForm::getSignGrade() const { return signGrade; }

int AForm::getExecGrade() const { return execGrade; }

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Form grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Form grade is too low";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "Form: " << form.getName()
		<< ", Status: " << (form.getIsSigned() ? "Signed" : "Unsigned")
		<< ", Required Grade to Sign: " << form.getSignGrade()
		<< ", Required Grade to Execute: " << form.getExecGrade() << ".";
	return os;
}
