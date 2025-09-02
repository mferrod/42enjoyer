#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main (void)
{
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	if(rrf != NULL)
		std::cout << *rrf << std::endl;
	delete rrf;
	AForm* scf;
	scf = someRandomIntern.makeForm("ShrubberyCreationForm","Bush");
	if (scf != NULL)
		std::cout << *scf << std::endl;
	delete scf;
	AForm* ppf;
	ppf = someRandomIntern.makeForm("PresidentialPardonForm","Mauri");
	if (ppf != NULL)
		std::cout << *ppf << std::endl;
	delete ppf;
	AForm* non;
	non = someRandomIntern.makeForm("Non","non");
	if(non != NULL)
		std::cout << *non <<std::endl;
	delete non;
}