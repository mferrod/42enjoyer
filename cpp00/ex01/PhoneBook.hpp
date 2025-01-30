#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		actualNumberContacts;
		void	replaceContactList(Contact contact);
		std::string	charWider(std::string str);
	public:
		PhoneBook();
		~PhoneBook();
		void addContact(Contact contact);
		void searchContact(int contactIndex);
		void listContacts();
		bool checkIfNumber(char *str);
};

#endif