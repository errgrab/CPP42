#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
    FragTrap fragTrap("FragTrap");
    ScavTrap scavTrap("ScavTrap");
    fragTrap.attack("ScavTrap");
    scavTrap.takeDamage(30);
    scavTrap.beRepaired(5);
    scavTrap.guardGate();
    fragTrap.highFivesGuys();
	return 0;
}
