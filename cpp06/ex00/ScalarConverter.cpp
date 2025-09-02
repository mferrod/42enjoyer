#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal) {
    float number = std::atof(literal.c_str());
	if (std::isnan(number)) {
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	} else if ((number >= 0 && number < 32) || number == 127) {
		std::cout << "char: " << "Non displayable" << std::endl;
		std::cout << "int: " << (int)number << std::endl;
		std::cout << "float: " << number << "f" << std::endl;
		std::cout << "double: " << (double)number << std::endl;
	} else if (number < 0 || number > 127) {
		std::cout << "char: " << "Non displayable" << std::endl;
		std::cout << "int: " << (int)number << std::endl;
		std::cout << "float: " << number << "f" << std::endl;
		std::cout << "double: " << (double)number << std::endl;
	} else if (number < -2147483648.f || number > 2147483647.f) {
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << number << "f" << std::endl;
		std::cout << "double: " << (double)number << std::endl;
	} else {
		std::cout << "char: " << (char)(int)number << std::endl;
		std::cout << "int: " << (int)number << std::endl;
		std::cout << "float: " << number << "f" << std::endl;
		std::cout << "double: " << (double)number << std::endl;
	}
}
