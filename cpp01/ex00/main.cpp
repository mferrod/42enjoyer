#include "Zombie.hpp"

int main(void)
{
	Zombie *z2 = newZombie("Z2");
	z2->announce();
	randomChump("PEPELUIS");
	delete z2;
	return 0;
}
