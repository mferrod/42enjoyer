#ifndef
# define Form

class Form {
	private:
		std::string const name;
		bool sign;
		int gradeToSign;
		int gradeToExecute;
	public:
		Form();
		~Form();
		Form(const Form &form);
		Form(std::string name, bool sign, int gradeToSign, int gradeToExecute);
		Form &operator=(const Form &other);

		std::string getName();
		bool isSigned();
		int getGradeToSign();
		int getGradeToExecute();
}

#endif