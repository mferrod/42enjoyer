#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	private:
		std::string type;
	public:
		WrongCat();
		WrongCat(const WrongCat &data);
		~WrongCat();
		WrongCat &operator=(const WrongCat &data);
		void makeSound();
};

#endif