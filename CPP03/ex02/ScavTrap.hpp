#pragma once

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap {
public:
    ScavTrap();
    ScavTrap(const std::string& name);
    ~ScavTrap();
    ScavTrap(const ScavTrap& scavTrap);
    ScavTrap& operator=(const ScavTrap& scavTrap);
    void guardGate();
};
