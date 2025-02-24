#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scav = ScavTrap("JUANLUIS");
	scav.guardGate();
	scav.attack("Scov");
	scav.beRepaired(10);
	scav.takeDamage(2);
	return 0;
}
