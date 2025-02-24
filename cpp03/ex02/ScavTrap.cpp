#include "ScavTrap.hpp"

ScavTrap :: ScavTrap() {
	std::cout << "Default ScavTrap CONSTRUCTOR CALLED" << std::endl;
}

ScavTrap :: ScavTrap(const ScavTrap &fix)
{
	//std::cout << "Copy constructor called";
	*this = fix;
}

ScavTrap :: ScavTrap(std::string name)
{
	std::cout << "ScavTrap name CONSTRUCTOR CALLED" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap& ScavTrap :: operator=(const ScavTrap &fix)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fix)
	{
		this->name = fix.name;
		this->hitPoints = fix.hitPoints;
		this->energyPoints = fix.energyPoints;
		this->attackDamage = fix.attackDamage;
	}
	return *this;
}

ScavTrap :: ~ScavTrap() {
	std::cout << "SCAVTRAP: DECONSTRUCTOR CALLED" << std::endl;
}

void ScavTrap :: guardGate() {
	std::cout << "ScavTrap " << this->name << "is now in Gate Keeper Mode" << std::endl;
}