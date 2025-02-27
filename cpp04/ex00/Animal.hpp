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
		~Animal();
		std::string getType() const;
		void setType(std::string type) ;
		void makeSound() const;
};

#endif