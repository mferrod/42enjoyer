#ifndef
# define Bureaucrat

class Bureaucrat {
	private:
		std::string const name;
		int grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		Bureaucrat(std::string const &name, int grade);
		
		std::string const getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		
};

#endif