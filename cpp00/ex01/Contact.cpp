#include "Contact.hpp"
#include <string>

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

std::string Contact :: getFirstName()
{
	return firstName;
}

std::string Contact :: getLastName()
{
	return lastName;
}

std::string Contact :: getNickName()
{
	return nickName;
}

std::string Contact :: getNumber()
{
	return number;
}

std::string Contact :: getSecret()
{
	return secret;
}

void Contact :: setFirstName(std::string str)
{
	this->firstName = str;
}

void Contact :: setLastName(std::string str)
{
	this->lastName = str;
}

void Contact :: setNickName(std::string str)
{
	this->nickName = str;
}

void Contact :: setNumber(std::string str)
{
	this->number = str;
}

void Contact :: setSecret(std::string str)
{
	this->secret = str;
}
