#include "Dog.hpp"

Dog::Dog() : type("Dog")
{
	std::cout << this->type << " default constructor called" << std::endl;
}

Dog::Dog(const Dog &d) : Animal(d)
{
	std::cout << this->type << " copy constructor called" << std::endl;
  *this = d;
}

Dog::~Dog()
{
	std::cout << this->type << " default destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &d)
{
  std::cout << this->type << " operator=() overload" << std::endl;
  this->type = d.type;
  return *this;
}


void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
