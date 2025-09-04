#include "Base.hpp"
#include <ctime>

int main() {
	std::srand((int)(std::time(NULL)));

	Base* obj = Base::generate();
	std::cout << "Identifying using pointer: ";
	Base::identify(obj);

	std::cout << "Identifying using reference: ";
	Base::identify(*obj);

	delete obj;
	return 0;
}