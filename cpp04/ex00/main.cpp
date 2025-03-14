#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal *Wrong = new WrongAnimal();
	const WrongAnimal *_cat = new WrongCat;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << _cat->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	_cat->makeSound();
	Wrong->makeSound();
	delete j;
	delete i;
	delete meta;
	delete _cat;
	delete Wrong;
	return 0;
}