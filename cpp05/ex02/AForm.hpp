#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"


class Bureaucrat;
class AForm
{
	private:
		const std::string name;
		bool sign;
		const int sigit;
		const int exeit;
	public:
		AForm();
		AForm &operator=(const AForm &data);
		AForm (const AForm &data);
		AForm(const char *nameP,const int sigitP,const int exeitP);
		std::string getName() const;
		bool getSign() const;
		int getSigit() const;
		int getExeit() const;
		void beSigned(Bureaucrat &person);
		virtual int execute(Bureaucrat const & executor) const = 0;
		class GradeTooHighException : public std::exception
		{
			public:
					const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
					const char *what() const throw();
		};
		virtual ~AForm();

};
std::ostream& operator<<(std::ostream& ret, AForm& data);
std::string IntToString(int num);
std::string BoolToString(bool data);
#endif