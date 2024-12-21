#include "Harl.hpp"
#include <iostream>
#include <string>
#include <cctype>

Harl::Harl() {};
Harl::~Harl() {};

void Harl::complain(std::string level) {
    for (unsigned long i = 0; i < level.size(); i++)
        level[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(level[i])));
    
    void (Harl::*funcs[4])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };

    std::string levels[4] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR",
    };

    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            (this->*funcs[i])();
            return;
        }
    }
    std::cerr << "Invalid argument" << std::endl;
}

void Harl::debug(void) {
    std::cout << "I love having bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enought bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
    std::cout << "This is unacceptable. I want to speak to the manager now." << std::endl;
}