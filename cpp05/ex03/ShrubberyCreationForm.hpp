#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "fstream"

class ShrubberyCreationForm:public AForm
{
	private:
			std::string target;
	public:
			ShrubberyCreationForm();
			~ShrubberyCreationForm();
			ShrubberyCreationForm &operator=(const ShrubberyCreationForm &data);
			ShrubberyCreationForm(const ShrubberyCreationForm &data);
			ShrubberyCreationForm(std::string target);
			int execute(Bureaucrat const & execute) const;
};
#endif