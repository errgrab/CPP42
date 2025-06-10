#pragma once

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {

private:
	const std::string name;
	bool isSigned;
	const int signGrade;
	const int execGrade;

public:
	AForm();
	AForm(const std::string& name, int signGrade, int execGrade);
	AForm(const AForm& other);
	~AForm();

	AForm& operator=(const AForm& other);

	const std::string& getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(const Bureaucrat& executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
