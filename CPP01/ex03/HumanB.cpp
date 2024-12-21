#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name), weapon(nullptr) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &newWeapon) {
    weapon = &newWeapon;
}

void HumanB::attack() const {
    if (weapon) {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    } else {
        std::cout << name << " attacks with their bare hands" << std::endl;
    }
}