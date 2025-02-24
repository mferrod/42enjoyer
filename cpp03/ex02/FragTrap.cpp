#include "FragTrap.hpp"

FragTrap :: FragTrap()
{
	std::cout << "Default FragTrap constructor" << std::endl;
}
FragTrap :: FragTrap(std::string name)
{
	std::cout << "FragTrap name constructor" << std::endl;
	this->name = name;
	this->attackDamage = 30;
	this->energyPoints = 100;
	this->hitPoints = 100;
}
FragTrap :: FragTrap(const FragTrap &fix)
{
	std::cout << "Call FragTrap copy constructor" << std::endl;
	*this = fix;
}
FragTrap :: ~FragTrap()
{
	std::cout << "Default Fragtrap deconstructor" << std::endl;
}
FragTrap& FragTrap :: operator=(const FragTrap &fix)
{
	std::cout << "FragTrap Copy assignament operator constructor called." << std::endl;
	if (this != &fix)
	{
		this->name = fix.name;
		this->hitPoints = fix.hitPoints;
		this->energyPoints = fix.energyPoints;
		this->attackDamage = fix.attackDamage;
	}
	return *this;
}

void FragTrap :: highFiveGuys(void)
{
	std::cout << "FragTrap " << this->name << "high fives!" << std::endl;
}