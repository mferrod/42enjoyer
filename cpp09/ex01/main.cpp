#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	RPN rpn;
	double result;
	if (!rpn.evaluate(argv[1], result)) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	if (result == static_cast<long>(result))
		std::cout << static_cast<long>(result) << std::endl;
	else
		std::cout << result << std::endl;

	return 0;
}
