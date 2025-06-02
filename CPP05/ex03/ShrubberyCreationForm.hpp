#pragma once

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
private:
	std::string target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

	virtual void execute(const Bureaucrat& executor) const;
	const std::string& getTarget() const;
};
