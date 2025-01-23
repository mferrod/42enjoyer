#include "Zombie.hpp"

int main(void)
{
	int zs = -10;
	Zombie* horde;
	horde = zombieHorde(zs, "pericopalotes");
	if (horde == NULL)
	{
		std::cerr << "Only positives numbers." << std::endl;
		return (1);
	}
	for (int i = 0; i < zs; i++)
		horde[i].announce();
	delete []horde;
	return (0);
}
