#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Call Brain default constructor" << std::endl;
}
Brain::Brain(Brain const &data)
{
	int i = 0;
	std::cout << "Call Brain copy constructor " << std::endl;
	while(i < 100)
	{
		this->ideas[i] = data.ideas[i];
		i++;
	}
}

Brain &Brain::operator=(const Brain &data)
{
	std::cout << "Call Brain Copy assignment operator" << std::endl;
	if(this != &data)
	{
		*this = data;
	}
	return(*this);
}
Brain::~Brain(void)
{
	std::cout << "Call Brain destructor default" << std::endl;
}