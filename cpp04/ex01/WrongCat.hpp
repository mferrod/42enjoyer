#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat :public WrongAnimal
{
	private:

	public:
			WrongCat();
			WrongCat(const WrongCat &data);
			WrongCat &operator=(const WrongCat &data);
			void makeSound() const;
			~WrongCat();
};


#endif