#include <iostream>

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

class ClapTrap
{
private:
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;
public:
	ClapTrap();
	ClapTrap(const ClapTrap &fix);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &fix);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	//GETTERS
	std::string getName(void) const;
	int getHitPoints(void) const;
	int getEnergyPoints(void) const;
	int getAttackDamage(void) const;

	//SETTERS
	void setName(std::string name);
	void setHitPoints(int points);
	void setEnergyPoints(int points);
	void setAttackDamage(int damage);
};

#endif