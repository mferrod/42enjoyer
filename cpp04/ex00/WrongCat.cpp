#include "WrongCat.hpp"

WrongCat :: WrongCat()
{
	std::cout << "Default WrongCat constructor called." << std::endl;
}

WrongCat :: WrongCat(const WrongCat &data)
{
	std::cout << "WrongCat Copy constructor called";
	*this = data;
}

WrongCat& WrongCat :: operator=(const WrongCat &data)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &data)
	{
		*this = data;
	}
	return *this;
}

WrongCat :: ~WrongCat()
{
	std::cout << "Default WrongCat destructor called." << std::endl;
}

void WrongCat :: makeSound()
{
	std::cout << "Wrong Cat Sound." << std::endl;
}