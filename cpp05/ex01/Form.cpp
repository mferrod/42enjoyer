#include "Form.hpp"

Form::Form():name("NULL"),sigit(0),exeit(0)
{
	std::cout << "Form constructor" << std::endl;
	this->sign = false;

}
Form::~Form()
{
	std::cout << "Destructor Form" << std::endl;
}
Form::Form(const Form &data):name(data.name),sigit(data.sigit),exeit(data.exeit)
{
	std::cout << "Form constructor copy" << std::endl;
	if (this != &data)
		*this = data;
}
Form::Form(const char *nameP,const int sigitP,const int exeitP):name(nameP),sigit(sigitP),exeit(exeitP)
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
Form &Form::operator=(const Form &data)
{
	std::cout << "Form assignament operator" << std::endl;
	this->sign = data.sign;
	return (*this);
}
void Form::beSigned(Bureaucrat &person)
{
	try
	{
		if(person.getGrade() > this->getSigit())
			throw(Form::GradeTooLowException());
		this->sign = true;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}
std::string Form::getName() const
{
	return(this->name);
}
int Form::getSigit() const
{
	return(this->sigit);
}
int Form::getExeit() const
{
	return(this->exeit);
}
bool Form::getSign() const
{
	return(this->sign);
}
const char *Form::GradeTooLowException::what() const throw()
{
	return("Error: Form Low Grade\n");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return("Error: Form High Grade\n");
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
std::ostream& operator<<(std::ostream& ret,Form& data)
{
	ret << data.getName() + " state bool " + BoolToString(data.getSign())
		+ " sigIt " + IntToString(data.getSigit())
		+ " sigExeit " + IntToString(data.getExeit());
	return(ret);
}