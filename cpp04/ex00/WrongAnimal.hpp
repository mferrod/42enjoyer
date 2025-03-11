#include <iostream>
#include <string>

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

class WrongAnimal
{
private:
	std::string type;
public:
	WrongAnimal(/* args */);
	~WrongAnimal();
	WrongAnimal &operator=(const WrongAnimal &data);
	std::string WrongAnimal :: getType() const;
	void setType(std::string type);
	void makeSound() const;
};


#endif