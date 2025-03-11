#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(/* args */)
{
}

WrongAnimal::~WrongAnimal()
{
}

WrongAnimal :: WrongAnimal(const WrongAnimal &data)
{
	//std::cout << "WrongAnimal Copy constructor called";
	*this = data;
}

WrongAnimal& WrongAnimal :: operator=(const WrongAnimal &data)
{
	//std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &data)
	{
		*this = data;
	}
	return *this;
}

std::string WrongAnimal :: getType() const
{
	return this->type;
}

void WrongAnimal :: setType(std::string type)
{
	this->type = type;
}

void WrongAnimal :: makeSound() const
{
	std::cout << "DEFAULT SOUND." << std::endl;
}
