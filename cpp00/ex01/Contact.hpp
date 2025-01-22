#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string number;
	std::string secret;
public:
	Contact();
	~Contact();

	//GETTERS
	std::string getFirstName();
	std::string getLastName();
	std::string getNickName();
	std::string getNumber();
	std::string getSecret();
	
	//SETTERS
	void setFirstName(std::string str);
	void setLastName(std::string str);
	void setNickName(std::string str);
	void setNumber(std::string str);
	void setSecret(std::string str);
};

#endif