#pragma once

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap {
public:
    FragTrap(std::string name);
    ~FragTrap();
    void highFivesGuys(void);
}
