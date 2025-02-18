#include "ScavTrap.hpp"

ScavTrap :: ScavTrap() {
	std::cout << "SCAVTRAP: CONSTRUCTOR CALLED" << std::endl;
	this->name = "NULL";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap :: ScavTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap :: ~ScavTrap() {
	std::cout << "SCAVTRAP: DECONSTRUCTOR CALLED" << std::endl;
}

void ScavTrap :: guardGate() {

}