#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		std::string getType();
		void setType(std::string type);
		void makeSound();
};

#endif