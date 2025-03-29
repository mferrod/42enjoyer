#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "Call WrongCat default constructor" << std::endl;
}
WrongCat::WrongCat(WrongCat const &data) : WrongAnimal ()
{
	std::cout << "Call WrongCat copy constructor " << std::endl;
	this->type = data.type;
}

WrongCat &WrongCat::operator=(const WrongCat &data)
{
	std::cout << "Call WrongCat Copy assignment operator" << std::endl;
	if(this != &data)
	{
		*this = data;
	}
	return(*this);
}
WrongCat::~WrongCat(void)
{
	std::cout << "Call WrongCat destructor default" << std::endl;
}
void WrongCat::makeSound(void) const
{
	std::cout << "Wrong Cat Sound." << std::endl;
}