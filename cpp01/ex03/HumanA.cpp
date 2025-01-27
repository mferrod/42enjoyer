#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon)
{
	this->name = name;
}

HumanA::~HumanA()
{
}

void HumanA :: attack() 
{
		std::cout << this->name + " attacks with their " + this->getWeapon().getType() << std::endl;
}

Weapon HumanA :: getWeapon()
{
	return this->weapon;
}

void HumanA :: setWeapon(Weapon weapon)
{
	this->weapon = weapon;
} 