#include "Dog.hpp"

Dog::Dog() : type("Dog")
{
	std::cout << this->type << " default constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::~Dog()
{
	std::cout << this->type << " default destructor called" << std::endl;
	delete this->brain;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
