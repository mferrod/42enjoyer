#include "ClapTrap.hpp"

ClapTrap :: ClapTrap()
{
	std::cout << "CONSTRUCTOR CALLED" << std::endl;
	this->attackDamage = 0;
	this->energyPoints = 10;
	this->hitPoints = 10;
	this->name = "NULL";
}

ClapTrap :: ~ClapTrap()
{
	std::cout << "DECONSTRUCTOR CALLED" << std::endl;
}

void ClapTrap :: takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " takes " << amount << " of damage" << std::endl;
	this->hitPoints - amount;
}

void ClapTrap :: beRepaired(unsigned int amount)
{
	if (this->energyPoints < amount)
	{
		std::cout << "ClapTrap can't be repaired, because the energy points are below than the total repair points." << std::endl;
		return ;
	}
	if (amount <= 0)
	{
		std::cout << "ClapTrap wasn't repair because the repair points are 0 or negative." << std::endl;
		return ;
	}
	else
	{
		this->energyPoints -= 1;
		this->hitPoints += amount;
	}	
}

void ClapTrap :: attack(const std::string& target)
{
	if (this->energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " can't attack because he hasn't enough energy points." << std::endl;
		return ;
	}
	if (this->hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << "can't attack because he hasn't enough attack points." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}