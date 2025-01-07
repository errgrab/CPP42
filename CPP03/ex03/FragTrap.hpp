#pragma once

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap {
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap& obj);
    ~FragTrap();
    FragTrap& operator=(const FragTrap& obj);
    void highFivesGuys(void);
};
