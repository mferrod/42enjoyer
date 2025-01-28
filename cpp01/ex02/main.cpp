#include <string>
#include <iostream>

int main(void)
{
	std::string myStr = "HI THIS IS BRAIN";
	std::string *stringPtr = &myStr;
	std::string &stringRef = myStr;

	std::cout << &myStr << std::endl;
	std::cout << stringPtr << std::endl;
	std::cout << &stringRef << std::endl;

	std::cout << myStr << std::endl;
	std::cout << *stringPtr << std::endl;
	std::cout << stringRef << std::endl;
	return 0;
}
