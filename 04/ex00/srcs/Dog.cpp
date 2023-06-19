#include "Dog.hpp"

Dog::Dog() : type("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog default destructor called" << std::endl;
}

std::string Dog::getType()
{
	return type;
}

void Dog::makeSound()
{
	std::cout << "Woof" << std::endl;
}
