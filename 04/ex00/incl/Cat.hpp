#pragma once
#ifndef __CAT_HPP__
#define __CAT_HPP__

#include <iostream>
#include "Animal.hpp"

class Cat: public Animal
{
private:

protected:
	std::string type;
public:
	Cat();
	virtual ~Cat();
  Cat(const Cat &c);
  Cat &operator=(const Cat &c);
	virtual void makeSound() const;
};

#endif
