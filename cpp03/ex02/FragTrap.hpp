#include "ClapTrap.hpp"

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

class FragTrap : public ClapTrap
{
	protected:

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &fix);
		~FragTrap();
		FragTrap &operator=(const FragTrap &fix);
		void highFiveGuys(void);
};
#endif