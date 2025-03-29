#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
			std::string type;
	public:
			WrongAnimal();
			WrongAnimal(const WrongAnimal &data);
			WrongAnimal &operator=(const WrongAnimal &data);
			void makeSound(void) const;
			~WrongAnimal();
			std::string getType(void) const;
};


#endif