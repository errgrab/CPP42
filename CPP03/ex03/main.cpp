#include "DiamondTrap.hpp"
#include <iostream>

int main(void) {
    DiamondTrap diamondTrap("DiamondTrap");
    diamondTrap.attack("ScavTrap");
    diamondTrap.takeDamage(30);
    diamondTrap.beRepaired(5);
    diamondTrap.guardGate();
    diamondTrap.highFivesGuys();
    diamondTrap.whoAmI();
	return 0;
}
