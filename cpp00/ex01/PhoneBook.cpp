#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <string>
#include <sstream>

PhoneBook::PhoneBook(void)
{
	this->actualNumberContacts = 0;
}

PhoneBook::~PhoneBook(void)
{
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
	for (int i = 0; i < this->actualNumberContacts - 1; i++)
		aux[i] = contacts[i + 1];
	aux[this->actualNumberContacts - 1] = contact;
	for (int i = 0; i < this->actualNumberContacts; i++)
		this->contacts[i] = aux[i];
}

void PhoneBook :: listContacts()
{
	std::cout << "INDEX\tFIRST NAME\tLAST NAME\tNICKNAME\n";
	for (int i = 0; i < this->actualNumberContacts; i++)
	{
		std::ostringstream oss;
		oss << i;
		std::cout << oss.str() + "\t|\t" + charWider(this->contacts[i].getFirstName()) + "\t|\t"
	+ charWider(this->contacts[i].getLastName()) + "\t|\t"
	+ charWider(this->contacts[i].getNickName()) << std::endl;
	}
}

void PhoneBook :: searchContact(int contactIndex)
{
	if (contactIndex > this->actualNumberContacts)
		return ;
	std::cout << "\n" +  charWider(this->contacts[contactIndex].getFirstName()) + "\n"
	+ charWider(this->contacts[contactIndex].getLastName()) + "\n"
	+ charWider(this->contacts[contactIndex].getNickName()) + "\n"
	+ charWider(this->contacts[contactIndex].getNumber()) + "\n"
	+ charWider(this->contacts[contactIndex].getSecret()) + "\n";
}

std::string PhoneBook :: charWider(std::string str)
{
	if (str.size() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}