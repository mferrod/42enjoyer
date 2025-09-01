Form::Form() : name("NULL"), sign(false), gradeToSign(100), gradeToExecute(100)
{
	std::cout << "Form default constructor" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor" << std::endl;
}
Form::Form(const Form &data):name(data.name),gradeToSign(data.gradeToSign),gradeToExecute(data.gradeToExecute)
{
	std::cout << "Form constructor copy" << std::endl;
	if (this != &data)
		*this = data;
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute)
{
	this->name = name;
	this->gradeToSign = gradeToSign;
	this->gradeToExecute = gradeToExecute;
}

Form &Form::operator=(const Form &data)
{
	std::cout << "Form assignament operator" << std::endl;
	this->sign = data.sign;
	return (*this);
}

std::string Form::Form getName(void) {
	return (this->name);
}

bool Form::Form isSigned(void) {
	return (this->sign);
}

int Form::Form getGradeToSign(void) {
	return (this->gradeToSign);
}

int Form::Form getGradeToExecute(void) {
	return (this->gradeToExecute);
}