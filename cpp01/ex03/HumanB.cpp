#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB()
{
}

void HumanB :: attack() 
{
	if (weapon)
		std::cout << this->name + " attacks with their " + this->getWeapon().getType() << std::endl;
	else
		std::cout << this->name + " doesnt have any weapons to attack" << std::endl;
}

Weapon HumanB :: getWeapon()
{
	return *this->weapon;
}

void HumanB :: setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}