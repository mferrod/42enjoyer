#include "Animal.hpp"

Animal :: Animal()
{
	std::cout << "Default Animal constructor called." << std::endl;
}

Animal :: ~Animal()
{
	std::cout << "Default Animal destructor called." << std::endl;
}

std::string Animal :: getType()
{
	return this->type;
}

void Animal :: setType(std::string type)
{
	this->type = type;
}

void Animal :: makeSound()
{
	std::cout << "DEFAULT SOUND." << std::endl;
}