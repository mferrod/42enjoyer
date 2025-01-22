#include <string>
#include <cstdlib>
#include "Contact.hpp"
#include "PhoneBook.hpp"
int main(void)
{
	PhoneBook phoneBook;
	std::cout << "WELCOME TO NEITOR'S PHONEBOOK!" << std::endl;
	std::string phrase;
	while (1)
	{
		std::cout << "TO ADD A CONTACT, TYPE ADD, TO SEARCH A CONTACT, TYPE SEARCH, TO EXIT, TYPE EXIT" << std::endl;
		std::getline(std::cin, phrase);
		if (phrase.empty())
			return (1);
		if (phrase == "ADD")
		{
			Contact contact;
			phoneBook.addContact(contact);	
		}
		else if (phrase == "SEARCH")
		{
			phoneBook.listContacts();
			std::string index;
			std::cout << "Type the contact index: ";
			std::getline(std::cin, index);
			phoneBook.searchContact(atoi(index.c_str()));
		}
		else if (phrase == "EXIT")
			break;
	}
	return (0);
}
