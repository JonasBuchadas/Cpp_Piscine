#pragma once

#include <iostream>

class AAnimal
{
private:

protected:
	std::string type;
public:
	AAnimal();
	AAnimal(const AAnimal& a);
	virtual ~AAnimal();

	AAnimal& operator=(const AAnimal& a);

	virtual void makeSound() const = 0;
	virtual std::string getType() = 0;
};

