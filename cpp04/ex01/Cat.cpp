#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Call Cat default constructor" << std::endl;
	this->ideas = new Brain;
}
Cat::Cat(Cat const &data) : Animal ()
{
	std::cout << "Call Cat copy constructor " << std::endl;
	this->type = data.type;
	this->ideas = new Brain(*data.ideas);
}

Cat &Cat::operator=(const Cat &data)
{
	std::cout << "Call Cat Copy assignment operator" << std::endl;
	if(this != &data)
	{
		delete this->ideas;
		this->ideas = new Brain(*data.ideas);
		this->type = data.type;
	}
	return(*this);
}
Cat::~Cat(void)
{
	std::cout << "Call Cat destructor default" << std::endl;
	delete this->ideas;
}
void Cat::makeSound(void) const
{
	std::cout << "MIAU MIAU" << std::endl;
}
