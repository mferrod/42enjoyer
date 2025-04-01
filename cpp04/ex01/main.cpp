#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	int x = 10;
	Animal *AnimalArray[x];
	int i = 0;
	std::cout << "Creating dog" << std::endl;
	while(i < x / 2)
	{
		AnimalArray[i] = new Dog();
		i++;
	}
	std::cout << "Creating cat" << std::endl;
	while(i < x)
	{
		AnimalArray[i] = new Cat();
		i++;
	}
	std::cout << "Creating animal sounds" << std::endl;
	i = 0;
	while(i < x)
	{
		AnimalArray[i]->getType();
		AnimalArray[i]->makeSound();
		i++;
	}
	i = 0;
	std::cout << "Calling destructor" << std::endl;
	while(i < x)
	{
		delete AnimalArray[i];
		i++;
	}
	std::cout << "Check deep copy" << std::endl;
	Dog		first_dog;
	Dog		second_dog = first_dog;
	std::cout << "First DOG address: " << &first_dog.getIdeas() << std::endl;
	std::cout << "Second DOG address: " << &second_dog.getIdeas() << std::endl;
}
