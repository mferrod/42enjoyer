#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <string>

PhoneBook::PhoneBook(void)
{
	this->actualNumberContacts = 0;
	std::cout << "PhoneBook default constructor called." << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook default deconstructor called." << std::endl;
}

void  PhoneBook :: addContact(Contact contact)
{
	std::string phrase;
	while (phrase == "")
	{
		std::cout << "ENTER FIRST NAME: ";
		std::getline(std::cin, phrase);
		if (std::cin.eof() || !std::cin.good())
			return;
	}
	contact.setFirstName(phrase);
	phrase.erase();
	while (phrase == "")
	{
		std::cout << "ENTER LAST NAME: ";
		std::getline(std::cin, phrase);
		if (std::cin.eof() || !std::cin.good())
			return;
	}
	contact.setLastName(phrase);
	phrase.erase();
	while (phrase == "")
	{
		std::cout << "ENTER NICKNAME: ";
		std::getline(std::cin, phrase);
		if (std::cin.eof() || !std::cin.good())
			return;
	}
	contact.setNickName(phrase);
	phrase.erase();
	while (phrase == "")
	{ //Hacer checker para ver que el número esté bien.
		std::cout << "ENTER NUMBER: ";
		std::getline(std::cin, phrase);
		if (std::cin.eof() || !std::cin.good())
			return;
	}
	contact.setNumber(phrase);
	phrase.erase();
	while (phrase == "")
	{
		std::cout << "ENTER SECRET: ";
		std::getline(std::cin, phrase);
		if (std::cin.eof() || !std::cin.good())
			return;
	}
	contact.setSecret(phrase);
	phrase.erase();
	if (this->actualNumberContacts == 8)
		this->replaceContactList(contact);
	else
	{
		this->contacts[this->actualNumberContacts] = contact;
		this->actualNumberContacts++;
	}
}

void PhoneBook :: replaceContactList(Contact contact)
{
	Contact aux[8];
	for (size_t i = 0; i < this->actualNumberContacts - 1; i++)
		aux[i] = contacts[i + 1];
	aux[this->actualNumberContacts - 1] = contact;
	for (size_t i = 0; i < this->actualNumberContacts; i++)
		this->contacts[i] = aux[i];
}
