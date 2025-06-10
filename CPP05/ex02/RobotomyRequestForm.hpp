#pragma once

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
private:
	std::string target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

	const std::string& getTarget() const;

	virtual void execute(const Bureaucrat& bureaucrat) const;
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form);
