#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main (void)
{
	Bureaucrat Mati("Mati",4);
	PresidentialPardonForm President("Mauri");
	President.beSigned(Mati);
	std::cout << President << std::endl;
	President.execute(Mati);

	Bureaucrat Han("Han",9);
	RobotomyRequestForm Robot("R2D2");
	Robot.beSigned(Han);
	std::cout << Robot << std::endl; 
	Robot.execute(Han);

	Bureaucrat Willy("Willy",50);
	ShrubberyCreationForm bush("BUSH");
	bush.beSigned(Willy);
	std::cout << bush << std::endl;
	bush.execute(Willy);

	Bureaucrat ringo("Ringo",4);
	ringo.executeForm(President);
}