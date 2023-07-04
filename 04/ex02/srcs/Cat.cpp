#include "Cat.hpp"

Cat::Cat() : type("Cat")
{
	std::cout << this->type << " default constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat &c) : AAnimal()
{
	this->type = c.type;
	if (c.brain)
		this->brain = new Brain(*c.brain);
	std::cout << this->type << " copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &c)
{
	std::cout << this->type << " = operator overload called" << std::endl;
	if (this == &c)
        return *this;
	this->type = c.type;
	this->brain = c.brain;
	return *this;
}

Cat::~Cat()
{
	std::cout << this->type << " default destructor called" << std::endl;
	delete this->brain;
}

std::string Cat::getType()
{
	return this->type;
}

Brain& Cat::getBrain()
{
	return *this->brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
