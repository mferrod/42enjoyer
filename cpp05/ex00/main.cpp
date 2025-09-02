#include "Bureaucrat.hpp"

int main (void)
{
	Bureaucrat *objectE = NULL;

	Bureaucrat objectA("Bureaucrat1", 100);
	Bureaucrat objectB("Bureaucrat2", 1);
	Bureaucrat objectC;
	Bureaucrat objectD(objectB);
	objectE = new Bureaucrat(objectA);
	std::cout << "objectA: " << objectA << "\n";
	std::cout << "objectB: " << objectB << "\n";
	std::cout << "objectC: " << objectC << "\n";
	objectD.decrementRange();
	std::cout << "objectD: " << objectD << "\n";
	objectD.incrementRange();
	std::cout << "objectE: " << *objectE << "\n";
	while (objectA.getGrade() < 150)
	{
		objectA.decrementRange();
		std::cout << "objectA: " << objectA << "\n";
	}
	delete objectE;
}