#include <string>
#include "Weapon.hpp"
#include <iostream>
#ifndef HUMANA_HPP
# define HUMANA_HPP
class HumanA
{
private:
	Weapon &weapon;
	std::string name;
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack();
	Weapon getWeapon();
	void setWeapon(Weapon weapon);
};

#endif
