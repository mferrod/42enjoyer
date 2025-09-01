#include "Bureaucrat.hpp"

int main (void)
{
	Bureaucrat *e = NULL;

	Bureaucrat objectA("Bureaucrat1", 100);
	Bureaucrat objectB("Bureaucrat2", 1);
	Bureaucrat objectC;
	Bureaucrat objectD(b);
	objectE = new Bureaucrat(a);
	std::cout << "objectA: " << objectA << "\n";
	std::cout << "objectB: " << objectB << "\n";
	std::cout << "objectC: " << objectC << "\n";
	objectD.decrementRange();
	std::cout << "objectD: " << objectD << "\n";
	objectD->incrementRange();
	std::cout << "objectE: " << *objectE << "\n";
	while (objectA.getGrade() <= 151)
	{
		objectA.decrementRange();
		std::cout << "objectA: " << objectA << "\n";
	}
	delete objectE;
}