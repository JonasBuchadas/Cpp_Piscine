#include "Dog.hpp"

Dog::Dog() : type("Dog") {
  std::cout << this->type << " default constructor called" << std::endl;
}

Dog::~Dog() {
  std::cout << this->type << " default destructor called" << std::endl;
}

Dog::Dog(const Dog &src) : Animal() {
  std::cout << this->type << " copy constructor called" << std::endl;
  *this = src;
}

Dog &Dog::operator=(const Dog &src) {
  std::cout << this->type << " = operator called" << std::endl;
  if (this == &src)
    return (*this);
  this->type = src.type;
  return (*this);
}

void Dog::makeSound() const { std::cout << "Woof" << std::endl; }

std::string Dog::getType() const { return type; }
