#include "Zombie.hpp"
#include <string>

Zombie :: Zombie() {
	
}

Zombie :: ~Zombie() {
	std::cout << "The zombie " + this->name + " was destroyed" << "\n";
}

void Zombie :: announce() {
	std::cout << this->name + ": BraiiiiiiinnnzzzZ..." << "\n";
}