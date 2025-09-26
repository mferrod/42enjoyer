#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::cout << "Default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

~BitcoinExchange::BitcoinExchange() {
	std::cout << "Destructor called" << std::endl;
} 

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		//Falta poner los atributos
	}
	return *this;
}