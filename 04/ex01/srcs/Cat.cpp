#include "Cat.hpp"

Cat::Cat() : type("Cat")
{
	std::cout << this->type << " default constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::~Cat()
{
	std::cout << this->type << " default destructor called" << std::endl;
	delete this->brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
