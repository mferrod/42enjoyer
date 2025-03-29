#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "Call WrongAnimal default constructor" << std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal const &data)
{
	std::cout << "Call WrongAnimal copy constructor " << std::endl;
	this->type = data.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &data)
{
	std::cout << "Call WrongAnimal Copy assignment operator" << std::endl;
	if(this != &data)
		*this = data;
	return(*this);
}
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Call WrongAnimal destructor default" << std::endl;
}
void WrongAnimal::makeSound(void) const
{
	std::cout << "Wrong Animal Sound." << std::endl;
}
std::string WrongAnimal::getType(void) const
{
	return(this->type);
}