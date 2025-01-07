#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ScavTrap("DiamondTrap_clap_name"), FragTrap("DiamondTrap_clap_name"), name("DiamondTrap") {
    std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), name(name) {
    std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ScavTrap(obj), FragTrap(obj), name(obj.name) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj) {
    FragTrap::operator=(obj);
    std::cout << "DiamondTrap assignation operator called" << std::endl;
    return *this;
}

std::string DiamondTrap::getName(void) {
    return name;
}

void DiamondTrap::attack(std::string const& target) {
    FragTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount) {
    ScavTrap::takeDamage(amount);
}

void DiamondTrap::beRepaired(unsigned int amount) {
    FragTrap::beRepaired(amount);
}

void DiamondTrap::whoAmI(void) {
    std::cout << "I am " << name << " and my ClapTrap name is " << FragTrap::getName() << std::endl;
}