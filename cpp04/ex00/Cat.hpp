#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	private:

	public:
		Cat();
		Cat(const Cat &data);
		~Cat();
		Cat &operator=(const Cat &data);
		void makeSound() const;
};

#endif