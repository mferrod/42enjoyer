#include "Dog.hpp"

Dog :: Dog()
{
	std::cout << "Default Dog constructor called." << std::endl;
}

Dog :: ~Dog()
{
	std::cout << "Default Dog destructor called." << std::endl;
}

Dog :: Dog(const Dog &fix)
{
	//std::cout << "Dog copy constructor called";
	*this = fix;
}

Dog& Dog :: operator=(const Dog &fix)
{
	//std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &fix)
	{
		this->type = fix.type;
	}
	return *this;
}

void Dog :: makeSound()
{
	std::cout << "GUAU GUAU" << std::endl;
}