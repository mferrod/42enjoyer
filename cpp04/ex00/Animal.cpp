#include "Animal.hpp"

Animal :: Animal()
{
	std::cout << "Default Animal constructor called." << std::endl;
}

Animal :: ~Animal()
{
	std::cout << "Default Animal destructor called." << std::endl;
}

Animal :: Animal(const Animal &data)
{
	std::cout << "Animal Copy constructor called";
	*this = data;
}

Animal& Animal :: operator=(const Animal &data)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &data)
	{
		*this = data;
	}
	return *this;
}

std::string Animal :: getType() const
{
	return this->type;
}

void Animal :: setType(std::string type)
{
	this->type = type;
}

void Animal :: makeSound() const
{
	std::cout << "DEFAULT SOUND." << std::endl;
}