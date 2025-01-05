#include "ClapTrap.hpp"

int main(void) {
	ClapTrap clapTrap("ClapTrap");
	ClapTrap clapTrap2(clapTrap);
	ClapTrap clapTrap3 = clapTrap;

	clapTrap.attack("target");
	clapTrap.takeDamage(10);
	clapTrap.beRepaired(5);

	return 0;
}
