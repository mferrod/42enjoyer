#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat :public Animal
{
	private:
			Brain *ideas;
	public:
			Cat();
			Cat(const Cat &data);
			Cat &operator=(const Cat &data);
			void makeSound() const;
			~Cat();
};


#endif