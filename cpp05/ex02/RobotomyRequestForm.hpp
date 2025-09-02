#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "ctime"
#include "cstdlib"

class RobotomyRequestForm:public AForm
{
	private:
			std::string target;
	public:
			RobotomyRequestForm();
			RobotomyRequestForm(const RobotomyRequestForm &data);
			RobotomyRequestForm &operator=(const RobotomyRequestForm &data);
			~RobotomyRequestForm();
			RobotomyRequestForm(std::string target);
			int execute(Bureaucrat const & execute) const;

};
#endif