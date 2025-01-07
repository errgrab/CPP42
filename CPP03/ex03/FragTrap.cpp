#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("FragTrap", 100, 100, 30) {
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj) {
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj) {
    ClapTrap::operator=(obj);
    std::cout << "FragTrap assignation operator called" << std::endl;
    return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->getName() << " requests a high five!" << std::endl;
}
