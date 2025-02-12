#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0)
{ 
	//std::cout << "Default constructor called" << std::endl; 
}
Fixed::Fixed(const Fixed &fix)
{
	*this = fix; 
	//std::cout << "Copy constructor called" << std::endl;
}
Fixed::Fixed(const int fixedPoint) : fixedPoint(fixedPoint << fractionalNumber) {
	//std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float fixedPoint) : fixedPoint(roundf(fixedPoint * (1 << fractionalNumber))) {
	//std::cout << "Float constructor called" << std::endl;
}
Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fix) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fix) this->fixedPoint = fix.fixedPoint;
	return *this;
}

bool Fixed::operator>(const Fixed &fix) const {
	return this->fixedPoint > fix.fixedPoint;
}
bool Fixed::operator<(const Fixed &fix) const {
	return this->fixedPoint < fix.fixedPoint;
}
bool Fixed::operator>=(const Fixed &fix) const {
	return this->fixedPoint >= fix.fixedPoint;
}
bool Fixed::operator<=(const Fixed &fix) const {
	return this->fixedPoint <= fix.fixedPoint;
}
bool Fixed::operator==(const Fixed &fix) const {
	return this->fixedPoint == fix.fixedPoint;
}
bool Fixed::operator!=(const Fixed &fix) const {
	return this->fixedPoint != fix.fixedPoint;
}

Fixed Fixed::operator+(const Fixed &fix) const {
	return Fixed(this->toFloat() + fix.toFloat());
}
Fixed Fixed::operator-(const Fixed &fix) const {
	return Fixed(this->toFloat() - fix.toFloat());
}
Fixed Fixed::operator*(const Fixed &fix) const {
	return Fixed(this->toFloat() * fix.toFloat());
}
Fixed Fixed::operator/(const Fixed &fix) const {
	if (fix.fixedPoint == 0) {
		std::cerr << "Error: Division by zero!" << std::endl;
		exit(1);
	}
	return Fixed(this->toFloat() / fix.toFloat());
}

Fixed &Fixed::operator++() {
	this->fixedPoint++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->fixedPoint++;
	return temp;
}

Fixed &Fixed::operator--() {
	this->fixedPoint--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->fixedPoint--;
	return temp;
}

int Fixed::toInt() const {
	return this->fixedPoint >> fractionalNumber;
}
float Fixed::toFloat() const {
	return (float)this->fixedPoint / (1 << fractionalNumber);
}

void Fixed::setRawBits(int const raw) {
	this->fixedPoint = raw;
}
int Fixed::getRawBits(void) const {
	return this->fixedPoint;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b; 
}

std::ostream &operator<<(std::ostream &out, const Fixed &fix) {
	out << fix.toFloat();
	return out;
}
