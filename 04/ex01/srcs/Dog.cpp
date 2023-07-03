#include "Dog.hpp"

Dog::Dog() : type("Dog")
{
	std::cout << this->type << " default constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog &d) : Animal()
{
	this->type = d.type;
	if (d.brain)
		this->brain = new Brain(*d.brain);
	std::cout << this->type << " copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &d)
{
	if (this == &d)
        return *this;
	this->type = d.type;
	this->brain = d.brain;
	std::cout << this->type << " = operator overload called" << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << this->type << " default destructor called" << std::endl;
	delete this->brain;
}

Brain& Dog::getBrain()
{
	return *this->brain;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
