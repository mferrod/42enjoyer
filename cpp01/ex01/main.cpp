#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"
int main(int argc, char const *argv[])
{
	PhoneBook phoneBook;
	std::cout << " WELCOME TO NEITOR'S PHONEBOOK! ";
	while (1)
	{

		std::string phrase;
		std::cout << "TO ADD A CONTACT, TYPE ADD, TO SEARCH A CONTACT, TYPE SEARCH";
		if (phrase == "ADD")
		{
			Contact contact;
			phoneBook.addContact(contact);	
		}
	}
	
	return 0;
}
