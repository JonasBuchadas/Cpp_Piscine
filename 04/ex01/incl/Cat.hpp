#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
private:
	Brain*	brain;
protected:
	std::string type;
public:
	Cat();
	virtual ~Cat();
	virtual void makeSound() const;
};

