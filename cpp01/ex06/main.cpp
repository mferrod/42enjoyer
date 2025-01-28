#include "Harl.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "Only 1 arguments" << std::endl;
		return 1;
	}
	Harl harl;
	harl.complain(argv[1]);
	return 0;
}
