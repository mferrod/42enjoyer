#include <string>
#include "Weapon.hpp"
#include <iostream>
#ifndef HUMANB_HPP
# define HUMANB_HPP
class HumanB
{
private:
	Weapon *weapon;
	std::string name;
public:
	HumanB(std::string name);
	~HumanB();
	void attack();
	Weapon getWeapon();
	void setWeapon(Weapon &weapon);
};

#endif