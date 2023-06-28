#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
private:
	Brain*	brain;
protected:
	std::string type;
public:
	Dog();
	virtual ~Dog();
	virtual void makeSound() const;
};

