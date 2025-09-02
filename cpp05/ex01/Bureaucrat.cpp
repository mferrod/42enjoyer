#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("NAME")
{
	std::cout << "Bureaucrat constructor" << std::endl;
	this->grade = 0;
}
Bureaucrat::Bureaucrat(const Bureaucrat &data):name(data.name)
{
	std::cout << "Bureaucrat constructor copy" << std::endl;
	if (this != &data)
		*this = data;
}
Bureaucrat::Bureaucrat(const char *nameP,int range):name(nameP)
{
	this->grade = range;
	try
	{
		if(range < 1)
			throw(Bureaucrat::GradeTooHighException());
		else if (range > 150)
			throw(Bureaucrat::GradeTooLowException());
	}
	catch(std::exception & e)
	{	
		std::cerr << e.what();
	}
}
void Bureaucrat::incrementRange(void)
{
	this->grade--;
	try
	{
		if(this->grade < 1)
			throw(Bureaucrat::GradeTooHighException());
		else if (this->grade > 150)
			throw(Bureaucrat::GradeTooLowException());
	}
	catch(std::exception & e)
	{	
		std::cerr << e.what();
	}
}
void Bureaucrat::decrementRange(void)
{
	this->grade++;
	try
	{
		if(this->grade < 1)
			throw(Bureaucrat::GradeTooHighException());
		else if (this->grade > 150)
			throw(Bureaucrat::GradeTooLowException());
	}
	catch(std::exception & e)
	{	
		std::cerr << e.what();
	}
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &data)
{
	std::cout << "Bureaucrat assignament operator" << std::endl;
	this->grade = data.grade;
	return *this;
}
const std::string Bureaucrat::getName()
{
	return(this->name);
}
int Bureaucrat::getGrade() const
{
	return(this->grade);
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Error: Bureaucrat Low Grade\n");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Error: Bureaucrat High Grade\n");
}
std::ostream& operator<<(std::ostream& ret,Bureaucrat& data)
{
	std::ostringstream oss;
	std::string str;
	oss << data.getGrade();
	str = oss.str();
	ret << data.getName() + ", bureaucrat grade " + str;
	return(ret);
}
void Bureaucrat::signForm(Form &data)
{
	try
	{
		if(data.getSign() != true)
			throw(GradeTooLowException());
		std::cout << this->name << " signed " << data.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name << " couldn't sign " << data.getName() << " because " << e.what();
	}
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor" << std::endl;
}