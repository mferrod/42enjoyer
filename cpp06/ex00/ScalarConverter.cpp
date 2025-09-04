#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal) {
    double number = std::atof(literal.c_str());

    if (std::isnan(number)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } else if (std::isinf(number)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << (number > 0 ? "inff" : "-inff") << std::endl;
        std::cout << "double: " << (number > 0 ? "inf" : "-inf") << std::endl;
    } else {
        if (number < -2147483648.0 || number > 2147483647.0) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
        } else {
            if (number >= 32 && number <= 126) {
                std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
            } else {
                std::cout << "char: Non displayable" << std::endl;
            }
            std::cout << "int: " << static_cast<int>(number) << std::endl;
        }
        std::cout << "float: " << static_cast<float>(number) << "f" << std::endl;
        std::cout << "double: " << number << std::endl;
    }
}

ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverter Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    std::cout << "ScalarConverter Copy Constructor called" << std::endl;
    if (this != &other) {
        *this = other;
    }
}

ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter Destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return (*this);
}
