#pragma once

#include <iostream>

class Animal
{
private:

protected:
	std::string type;
public:
	Animal();
	virtual ~Animal();
	virtual void makeSound() const;
	std::string getType() const;
};

