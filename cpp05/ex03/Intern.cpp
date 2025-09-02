#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Constructor" << std::endl;
}
Intern &Intern::operator=(const Intern &data)
{
	std::cout << "Intern Assignament operator" << std::endl;
	(void)data;
	return(*this);
}

Intern::Intern(const Intern &data)
{
	std::cout << "Intern Constructor copy" << std::endl;
	if(this != &data)
		*this = data;
}
Intern::~Intern()
{
	std::cout << "Intern Destructor" << std::endl;
}
AForm *Intern::makeForm(std::string nameForm,std::string targetForm)
{
	AForm *ret = NULL;
	int i = 0;
	std::string arr[] = {"ShrubberyCreationForm","RobotomyRequestForm","PresidentialPardonForm"};
	while(i < 3)
	{
		if(nameForm == arr[i])
			break;
		i++;
	}
	switch (i)
	{
		case 0:
			ret = new ShrubberyCreationForm(targetForm);
			std::cout << "Intern creates " << nameForm << std::endl;
			return(ret);
		case 1:
			ret = new RobotomyRequestForm(targetForm);
			std::cout << "Intern creates " << nameForm << std::endl;
			return(ret);
		case 2:
			ret = new PresidentialPardonForm(targetForm);
			std::cout << "Intern creates " << nameForm << std::endl;
			return(ret);
		default:
			std::cout << "The form does not exist" << std::endl;
			return(NULL);
	}
}