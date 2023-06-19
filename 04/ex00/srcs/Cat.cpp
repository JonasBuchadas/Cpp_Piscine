#include "Cat.hpp"

Cat::Cat() : type("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat default destructor called" << std::endl;
}

std::string Cat::getType()
{
	return type;
}

void Cat::makeSound()
{
	std::cout << "Meow" << std::endl;
}
