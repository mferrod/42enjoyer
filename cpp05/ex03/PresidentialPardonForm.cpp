#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():target("TARGET")
{
	std::cout << "Constructor PresidentialPardonForm" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &data):AForm("PresidentialPardonForm",25,5),target(data.target)
{
	std::cout << "Constructor copy PresidentialPardonForm" << std::endl;
	if(this != &data)
		*this = data;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &data)
{
	std::cout << "PresidentialPardonForm Assignament Operator" << std::endl;
	(void)data;
	return(*this);
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor PresidentialPardonForm" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm("PresidentialPardonForm",25,5)
{
	std::cout << "Constructor PresidentialPardonForm target" << std::endl;
	this->target = target;
}
int PresidentialPardonForm::execute(Bureaucrat const & execute) const
{
	try
	{
		if(execute.getGrade() > this->getExeit())
			throw(AForm::GradeTooLowException());
		if(execute.getGrade() < 1)
			throw(AForm::GradeTooHighException());
		if(this->getSign() == true)
			std::cout << "Informs that " << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
		else
		{
			std::cout << "It is not signed" << std::endl;
			return(1);
		}
		return(0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
		return(1);
	}
}
