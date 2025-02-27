#include "Cat.hpp"

Cat :: Cat()
{
	std::cout << "Default Cat constructor called." << std::endl;
}

Cat :: Cat(const Cat &data)
{
	//std::cout << "Cat Copy constructor called";
	*this = data;
}

Cat& Cat :: operator=(const Cat &data)
{
	//std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &data)
	{
		*this = data;
	}
	return *this;
}

Cat :: ~Cat()
{
	std::cout << "Default Cat destructor called." << std::endl;
}

void Cat :: makeSound()
{
	std::cout << "MIAU MIAU" << std::endl;
}