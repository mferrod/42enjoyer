#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {
	std::cout << "Bureaucrat default constructor" << std::endl;
	this->grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
	std::cout << "Bureaucrat constructor copy" << std::endl;
	if (this != &other)
		*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "Bureaucrat assignment operator" << std::endl;
	if (this != &other) {
		grade = other.grade;
	}
	return *this;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : name(name), grade(grade)
{
	this->grade = grade;
	try
	{
		if(grade < 1)
			throw(Bureaucrat::GradeTooHighException());
		else if (grade > 150)
			throw(Bureaucrat::GradeTooLowException());
	}
	catch(std::exception & e)
	{	
		std::cerr << e.what();
	}
}

std::string Bureaucrat::getName() {
	return (this->name);
}

int Bureaucrat::getGrade() {
	return (this->grade);
}

void Bureaucrat::incrementGrade() {
	try {
		--grade;
		if (grade < 1) {
			throw Bureaucrat::GradeTooHighException();
		}
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what();
	}
}

void Bureaucrat::decrementGrade() {
	try {
		++grade;
		if (grade > 150) {
			throw Bureaucrat::GradeTooLowException();
		}
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what();
	}
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Error: Low Grade\n");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Error: High Grade\n");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Error: High\n");
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
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor" << std::endl;
}