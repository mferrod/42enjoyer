#include <iostream>
#include <math.h>

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
	int fixedPoint;
	static const int fractionalNumber = 8;
public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &fix);
	~Fixed();
	Fixed &operator=(const Fixed &fix);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat(void) const;
	int toInt(void) const;
};
std::ostream &operator<<(std::ostream &o, const Fixed &ex);
#endif