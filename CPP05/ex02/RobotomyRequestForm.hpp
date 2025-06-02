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
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

	virtual void execute(const Bureaucrat& executor) const;
	const std::string& getTarget() const;
};
