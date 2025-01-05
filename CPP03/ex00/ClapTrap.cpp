#include <iostream>
#include <string>
#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : name(""), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = obj;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj) {
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &obj) {
		name = obj.name;
		hitPoints = obj.hitPoints;
		energyPoints = obj.energyPoints;
		attackDamage = obj.attackDamage;
	}
	return *this;
}

void ClapTrap::attack(std::string const& target) {
	std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << name << " is repaired for " << amount << " points!" << std::endl;
}

std::string ClapTrap::getName() {
	return name;
}

unsigned int ClapTrap::getHitPoints() {
	return hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() {
	return energyPoints;
}

unsigned int ClapTrap::getAttackDamage() {
	return attackDamage;
}

void ClapTrap::setName(std::string name) {
	this->name = name;
}

void ClapTrap::setHitPoints(unsigned int hitPoints) {
	this->hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
	this->energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage) {
	this->attackDamage = attackDamage;
}
