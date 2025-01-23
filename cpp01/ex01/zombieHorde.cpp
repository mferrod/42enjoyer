#include "Zombie.hpp"

void Zombie :: setZName(std::string name)
{
	this->name = name;
}

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return (NULL);
	Zombie* z;
	z = new Zombie[N];
	for (int i = 0; i < N; i++)
		z[i].setZName(name);
	return z;
}