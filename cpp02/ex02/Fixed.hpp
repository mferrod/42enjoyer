#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int fixedPoint;
	static const int fractionalNumber = 8;

public:
	Fixed();
	Fixed(const Fixed &fix);
	Fixed(const int number);
	Fixed(const float number);
	~Fixed();


	Fixed &operator=(const Fixed &fix);
	bool operator>(const Fixed &fix) const;
	bool operator<(const Fixed &fix) const;
	bool operator>=(const Fixed &fix) const;
	bool operator<=(const Fixed &fix) const;
	bool operator==(const Fixed &fix) const;
	bool operator!=(const Fixed &fix) const;

	Fixed operator+(const Fixed &fix) const;
	Fixed operator-(const Fixed &fix) const;
	Fixed operator*(const Fixed &fix) const;
	Fixed operator/(const Fixed &fix) const;

	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	int 	toInt() const;
	float	toFloat() const;

	void	setRawBits(int const raw);
	int		getRawBits(void) const;

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fix);

#endif
