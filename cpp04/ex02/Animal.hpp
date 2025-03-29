#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
			std::string type;
	public:
			Animal();
			Animal(const Animal &data);
			Animal &operator=(const Animal &data);
			virtual void makeSound(void) const = 0;
			virtual ~Animal();
			std::string getType(void) const;
};


#endif