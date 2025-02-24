#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap = ClapTrap("Clap");
	ClapTrap clop = ClapTrap("Clop");
	clap.takeDamage(4);
	clap.beRepaired(20);
	clap.attack("Clop");
	return 0;
}
