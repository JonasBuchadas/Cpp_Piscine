#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
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

	std::string getType();
	Brain& getBrain();

	void makeSound() const;
};

