#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("Default") {}

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

void ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const {
    if (!this->getIsSigned())
        std::cout << this->getName() << "Could not execute because form is not signed." << std::endl;

    if (bureaucrat.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();

    std::ofstream file(this->target + "_shrubbery");
    if (!file.is_open())
        throw std::ios_base::failure("Failed to open file");
    file << "                   .s.s.\n"
         << "                , `'`Y8bso.\n"
         << "              ,d88bso y 'd8l\n"
         << "              \"`,8K j8P?*?b.\n"
         << "             ,bonsai_`o.o\n"
         << "        ,r.osbJ--','  e8b?Y\n"
         << "       j*Y888P*{ `._.-'\" 888b\n"
         << "         `\"'``  `'-. `\"*?*P\"\n"
         << "          db8sld-'., ,):5ls.\n"
         << "     <sd88P,-d888P'd888d8888Rdbc\n"
         << "     `\"*J*CJ8*d8888l:'  ``88?bl.o\n"
         << "     .o.sl.rsdP^*8bdbs.. *\"?**l888s.\n"
         << "   ,`JYsd88P88ld?\\**\"`*`-. `  ` `\"`\n"
         << "  dPJ88*J?P;Pd888D;=-.  -.l.s.\n"
         << ".'`\"*Y,.sbsdkC L.    ?(     ^.   l\n"
         << "     .Y8*?8P*\"`       `)` .' :   b\n"
         << "       `\"`         _.-'. ,   k.  s\n"
         << "                  (    : '  ('\n"
         << "        _______ ,'`-  )`.` `.l  ___\n"
         << "     r========-==-==-=-=-=-----------=7\n"
         << "      `Y - -- ---- -- -   .         ,'\n"
         << "        :                     '    :\n"
         << "         \\-.. .. .. . . . . .    ,/\n"
         << "    .-<=:`._______________________,'.:>-.\n"
         << "    L_______                         ___J\n"
         << "            `````````````````````````\n";
    file.close();
}
