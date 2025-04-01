#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Call Animal default constructor" << std::endl;
	type = "Unkown";
}
Animal::Animal(Animal const &data)
{
	std::cout << "Call Animal copy constructor " << std::endl;
	this->type = data.type;
}

Animal &Animal::operator=(const Animal &data)
{
	std::cout << "Call Animal Copy assignment operator" << std::endl;
	if(this != &data)
	{
		*this = data;
	}
	return(*this);
}
Animal::~Animal(void)
{
	std::cout << "Call Animal destructor default" << std::endl;
}
void Animal::makeSound(void) const
{
	std::cout << "Animal sound" << std::endl;
}
std::string Animal::getType(void) const
{
	return(this->type);
}