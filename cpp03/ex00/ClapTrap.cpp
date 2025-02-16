#include "ClapTrap.hpp"

ClapTrap :: ClapTrap()
{
	std::cout << "CONSTRUCTOR CALLED" << std::endl;
	this->attackDamage = 0;
	this->energyPoints = 10;
	this->hitPoints = 10;
	this->name = "NULL";
}

ClapTrap :: ClapTrap(const ClapTrap &fix)
{
	//std::cout << "Copy constructor called";
	*this = fix;
}

ClapTrap :: ~ClapTrap()
{
	std::cout << "DECONSTRUCTOR CALLED" << std::endl;
}

ClapTrap& ClapTrap :: operator=(const ClapTrap &fix)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fix)
	{
		this->setName(fix.getName());
		this->setHitPoints(fix.getHitPoints());
		this->setEnergyPoints(fix.getEnergyPoints());
		this->setAttackDamage(fix.getAttackDamage());
	}
	return *this;
}

void ClapTrap :: takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " takes " << amount << " of damage" << std::endl;
	this->hitPoints - amount;
}

void ClapTrap :: beRepaired(unsigned int amount)
{
	if (this->energyPoints <= 0)
	{
		std::cout << "ClapTrap can't be repaired, because the energy points is zero or negative." << std::endl;
		return ;
	}
	if (amount <= 0)
	{
		std::cout << "ClapTrap wasn't repair because the repair points are zero or negative." << std::endl;
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

std::string ClapTrap :: getName(void) const
{
	return this->name; 
}

int ClapTrap :: getHitPoints(void) const
{
	return this->hitPoints;
}

int ClapTrap :: getEnergyPoints(void) const
{
	return this->energyPoints;
}

int ClapTrap :: getAttackDamage(void) const
{
	return this->attackDamage;
}

void ClapTrap :: setName(std::string name)
{
	this->name = name;
}

void ClapTrap :: setHitPoints(int points)
{
	this->hitPoints = points;
}

void ClapTrap :: setEnergyPoints(int points)
{
	this->energyPoints = points;
}

void ClapTrap :: setAttackDamage(int damage)
{
	this->attackDamage = damage;
}