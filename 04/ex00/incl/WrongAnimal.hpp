#pragma once

#include <iostream>

class WrongAnimal
{
private:

protected:
	std::string type;
public:
	WrongAnimal();
	~WrongAnimal();
	void makeSound() const;
	std::string getType() const;
};

