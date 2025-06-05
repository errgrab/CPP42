#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target(other.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

const std::string& ShrubberyCreationForm::getTarget() const {
	return target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();

	std::string filename = target + "_shrubbery";
	std::ofstream outFile(filename.c_str());
	if (!outFile.is_open())
		throw std::runtime_error("Could not create output file");

	outFile << "	  /\\	  " << std::endl;
	outFile << "	 /\\*\\	 " << std::endl;
	outFile << "	/\\O\\*\\	" << std::endl;
	outFile << "   /*/\\/\\/\\   " << std::endl;
	outFile << "  /\\O\\/\\*\\/\\  " << std::endl;
	outFile << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	outFile << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	outFile << "	  ||	  " << std::endl;
	outFile << "	  ||	  " << std::endl;
	outFile << "	  ||	  " << std::endl;

	outFile.close();
}
