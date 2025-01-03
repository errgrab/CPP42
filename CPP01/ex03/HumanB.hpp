#pragma once

#include <string>
#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon *weapon;
public:
    HumanB(std::string name);
    ~HumanB();
    void setWeapon(Weapon &newWeapon);
    void attack() const;
};