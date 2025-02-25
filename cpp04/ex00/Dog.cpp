#include "Dog.hpp"

Dog :: Dog()
{
	std::cout << "Default Dog constructor called." << std::endl;
}

Dog :: ~Dog()
{
	std::cout << "Default Dog destructor called." << std::endl;
}

void Dog :: makeSound()
{
	std::cout << "GUAU GUAU" << std::endl;
}