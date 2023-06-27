#include "Cat.hpp"

Cat::Cat() : type("Cat")
{
	std::cout << this->type << " default constructor called" << std::endl;
}

Cat::Cat(const Cat &c) : Animal(c)
{
	std::cout << this->type << " copy constructor called" << std::endl;
  *this = c;
}

Cat &Cat::operator=(const Cat &c)
{
  std::cout << this->type << " operator=() overload" << std::endl;
  this->type = c.type;
  return *this;
}

Cat::~Cat()
{
	std::cout << this->type << " default destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
