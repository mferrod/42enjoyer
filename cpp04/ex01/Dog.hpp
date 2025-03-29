#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog:public Animal
{
	private:
			Brain *ideas;
	public:
			Dog();
			Dog(const Dog &data);
			Dog &operator=(const Dog &data);
			void makeSound() const;
			~Dog();

			Brain& getIdeas(void) const;
};


#endif