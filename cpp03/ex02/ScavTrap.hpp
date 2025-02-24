#include "ClapTrap.hpp"

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

class ScavTrap : public ClapTrap {
private:
	
public:
	ScavTrap();
	ScavTrap :: ScavTrap(const ScavTrap &fix);
	ScavTrap& ScavTrap :: operator=(const ScavTrap &fix);
	ScavTrap :: ScavTrap(std::string name);
	~ScavTrap();
	void guardGate();
};

#endif