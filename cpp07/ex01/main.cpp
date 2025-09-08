#include "iter.hpp"

void addOne(int &n) { n += 1; }
void addExclamation(std::string &s) { s += "!"; }
void doubleValue(double &d) { d *= 2; }

int main(void) {
	int intArray[] = {0, 1, 2, 3, 4};
	std::string strArray[] = {"Hello", "World", "from", "iter", "template"};
	double doubleArray[] = {0.1, 1.2, 2.3, 3.4, 4.5};
	size_t length = 5;
	iter(intArray, length, addOne);
	iter(strArray, length, addExclamation);
	iter(doubleArray, length, doubleValue);
	for (size_t i = 0; i < length; ++i) {
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;
	for (size_t i = 0; i < length; ++i) {
		std::cout << strArray[i] << " ";
	}
	std::cout << std::endl;
	for (size_t i = 0; i < length; ++i) {
		std::cout << doubleArray[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}