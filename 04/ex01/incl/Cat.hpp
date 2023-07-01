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
	Cat(const Cat& c);
	virtual ~Cat();

	Cat& operator=(const Cat &c);

	Brain& getBrain();
	void setBrain(Brain &b);

	virtual void makeSound() const;
};

