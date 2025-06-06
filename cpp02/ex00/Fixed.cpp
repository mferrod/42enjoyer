#include "Fixed.hpp"

Fixed :: Fixed()
{
	//std::cout << "Default constructor called." << std::endl;
	this->fixedPoint = 0;
}

Fixed :: Fixed(const Fixed &fix)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

Fixed :: ~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed :: operator=(const Fixed &fix)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fix)
		this->setRawBits(fix.getRawBits());
	return *this;
}

int Fixed :: getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPoint;
}

void Fixed :: setRawBits(int const raw)
{
	this->fixedPoint = raw;
}