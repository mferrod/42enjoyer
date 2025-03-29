#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Call Dog default constructor" << std::endl;
	this->ideas = new Brain;
}
Dog::Dog(Dog const &data) : Animal ()
{
	std::cout << "Call Dog copy constructor " << std::endl;
	this->type = data.type;
	this->ideas = new Brain(*data.ideas);
}

Dog &Dog::operator=(const Dog &data)
{
	std::cout << "Call Dog Copy assignment operator" << std::endl;
	if(this != &data)
	{
		delete this->ideas;
		this->ideas = new Brain(*data.ideas);
		this->type = data.type;
	}
	return(*this);
}
Dog::~Dog(void)
{
	std::cout << "Call Dog destructor default" << std::endl;
	delete this->ideas;
}
void Dog :: makeSound(void) const
{
	std::cout << "GUAU GUAU" << std::endl;
}
Brain& Dog::getIdeas(void) const
{
	return *this->ideas;
}