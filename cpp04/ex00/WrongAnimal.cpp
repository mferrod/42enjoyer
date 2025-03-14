#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "Call WrongAnimal default constructor" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Call WrongAnimal default desconstructor" << std::endl;
}

WrongAnimal :: WrongAnimal(const WrongAnimal &data)
{
	std::cout << "WrongAnimal Copy constructor called";
	*this = data;
}

WrongAnimal& WrongAnimal :: operator=(const WrongAnimal &data)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &data)
	{
		*this = data;
	}
	return *this;
}

std::string WrongAnimal :: getType(void) const
{
	return this->type;
}

void WrongAnimal :: setType(std::string type)
{
	this->type = type;
}

void WrongAnimal :: makeSound() const
{
	std::cout << "WrongAnimal SOUND." << std::endl;
}
