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
	~ShrubberyCreationForm();

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

	const std::string& getTarget() const;

	virtual void execute(const Bureaucrat& bureaucrat) const;

	class FileCouldNotOpenException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form);
