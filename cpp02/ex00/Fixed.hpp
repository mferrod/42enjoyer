#include <iostream>

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
	int fixedPoint;
	static const int fractionalNumber = 8;
public:
	Fixed();
	Fixed(const Fixed &fix);
	~Fixed();
	Fixed &operator=(const Fixed &fix);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif