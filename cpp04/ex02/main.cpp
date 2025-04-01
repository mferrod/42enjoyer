#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    Dog dog;
    Animal *animal = new Dog(dog);
    std::cout << "Animal type: " << animal->getType() << std::endl;
    delete animal;
    return 0;
}