#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;
class Intern
{
	private:

	public:
		Intern();
		~Intern();
		Intern & operator=(const Intern &data);
		Intern(const Intern &data);
		AForm *makeForm(std::string nameForm,std::string targetForm);
};
#endif