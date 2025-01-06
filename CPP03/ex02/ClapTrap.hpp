#pragma once
#include <string>

class ClapTrap {
private:
	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
	ClapTrap(const ClapTrap& obj);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap& obj);
	void attack(std::string const& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string getName();
	unsigned int getHitPoints();
	unsigned int getEnergyPoints();
	unsigned int getAttackDamage();
	void setName(std::string name);
	void setHitPoints(unsigned int hitPoints);
	void setEnergyPoints(unsigned int energyPoints);
	void setAttackDamage(unsigned int attackDamage);
};
