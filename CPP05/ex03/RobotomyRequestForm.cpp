#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target(other.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

const std::string& RobotomyRequestForm::getTarget() const {
	return target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	try {
		if (!this->getIsSigned())
			throw AForm::FormNotSignedException();

		if (executor.getGrade() > this->getExecGrade())
			throw AForm::GradeTooLowException();
		
		std::srand(std::time(0));

		if (std::rand() % 2 == 0)
			std::cout << this->target << " has been robotomized!" << std::endl;
		else
			std::cout << "Robotomy failed for " << this->target << "!" << std::endl;
	} catch (const std::exception &e) {
		std::cerr << executor.getName() << " could not execute form " << this->getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form) {
	os << "RobotomyRequestForm: " << form.getName() 
		<< ", Target: " << form.getTarget() 
		<< ", Signed: " << (form.getIsSigned() ? "Yes" : "No") 
		<< ", Sign Grade: " << form.getSignGrade() 
		<< ", Exec Grade: " << form.getExecGrade();
	return os;
}
