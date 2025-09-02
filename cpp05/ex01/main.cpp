#include "Bureaucrat.hpp"
#include "Form.hpp"

int main (void)
{
	// VALID FORM
		Bureaucrat bureaucrat("Juan", 130);
		Form form("Formulario number one", 140, 140);
		form.beSigned(bureaucrat);
		bureaucrat.signForm(form);

	// INVALID SIGN
		Bureaucrat bureaucrat2("Pepe", 160);
		Form form2("Formulario number two", 120, 120);
		form2.beSigned(bureaucrat2);
		bureaucrat2.signForm(form2);
	
	return 0;
}