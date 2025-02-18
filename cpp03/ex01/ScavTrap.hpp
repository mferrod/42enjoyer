#include "ClapTrap.hpp"

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

class ScavTrap : public ClapTrap {
private:
	
public:
	ScavTrap();
	ScavTrap :: ScavTrap(std::string name);
	~ScavTrap();
	void guardGate();
};

#endif