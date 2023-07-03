#include "Cat.hpp"

Cat::Cat() : type("Cat")
{
	std::cout << this->type << " default constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat &c) : Animal()
{
	this->type = c.type;
	this->brain = c.brain;
	std::cout << this->type << " copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &c)
{
	this->type = c.type;
	*(this->brain) = *c.brain;
	std::cout << this->type << " = operator overload called" << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << this->type << " default destructor called" << std::endl;
	delete this->brain;
}

Brain& Cat::getBrain()
{
	return *this->brain;
}

void Cat::setBrain(Brain &b)
{
	*(this->brain) = b;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
