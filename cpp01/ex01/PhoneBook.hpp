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
	public:
		PhoneBook();
		~PhoneBook();
		void addContact(Contact contact);
};

#endif