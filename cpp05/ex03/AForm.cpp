#include "AForm.hpp"

AForm::AForm():name("NULL"),sigit(0),exeit(0)
{
	std::cout << "AForm constructor" << std::endl;
	this->sign = false;
}
AForm::AForm(const AForm &data):name(data.name),sigit(data.sigit),exeit(data.exeit)
{
	std::cout << "AForm constructor copy" << std::endl;
	if (this != &data)
		*this = data;
	}
AForm::AForm(const char *nameP,const int sigitP,const int exeitP):name(nameP),sigit(sigitP),exeit(exeitP)
{
	try
		{
			if(sigitP > 150 || exeitP > 150)
			throw(GradeTooLowException());
			else if (sigitP < 1 || exeitP < 1)
			throw(GradeTooHighException());
		}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}
AForm &AForm::operator=(const AForm &data)
{
	std::cout << "AForm Assignament operator" << std::endl;
	this->sign = data.sign;
	return (*this);
}
std::string AForm::getName() const
{
	return(this->name);
}
int AForm::getSigit() const
{
	return(this->sigit);
}
int AForm::getExeit() const
{
	return(this->exeit);
}
bool AForm::getSign() const
{
	return(this->sign);
}
const char *AForm::GradeTooLowException::what() const throw()
{
	return("Error Form: Low\n");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return("Error Form: High\n");
}
void AForm::beSigned(Bureaucrat &person)
{
	try
	{
		if(person.getGrade() > this->getSigit())
			throw(AForm::GradeTooLowException());
		this->sign = true;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}
std::string IntToString(int num)
{
	std::ostringstream oss;
	std::string str;
	oss << num;
	str = oss.str();
	return(str);
}
std::string BoolToString(bool data)
{
	if(data == true)
		return("True");
	return("False");
}
std::ostream& operator<<(std::ostream& ret,AForm& data)
{
	ret << data.getName() + " state bool " + BoolToString(data.getSign())
		+ " sigIt " + IntToString(data.getSigit())
		+ " sigExeit " + IntToString(data.getExeit());
	return(ret);
}
AForm::~AForm()
{
	std::cout << "Destructor Form" << std::endl;
}