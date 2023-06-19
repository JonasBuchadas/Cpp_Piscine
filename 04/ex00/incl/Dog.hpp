#pragma once
#ifndef __DOG_HPP__
#define __DOG_HPP__

#include <iostream>
#include "Animal.hpp"

class Dog: public Animal
{
private:

protected:
	std::string type;
public:
	Dog();
	~Dog();
	void makeSound();
	std::string getType();
};

#endif
