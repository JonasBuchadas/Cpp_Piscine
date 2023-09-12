#include "Dog.hpp"

Dog::Dog() : type("Dog") {
  std::cout << this->type << " default constructor called" << std::endl;
  this->brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal(src) {
  if (src.brain)
    this->brain = new Brain();
  *this = src;
  std::cout << this->type << " copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &src) {
  if (this == &src)
    return *this;
  this->type = src.type;
  if (this->brain)
    delete this->brain;
  if (src.brain)
    this->brain = new Brain(*src.brain);
  else
    this->brain = NULL;
  std::cout << this->type << " = operator overload called" << std::endl;
  return *this;
}

Dog::~Dog() {
  std::cout << this->type << " default destructor called" << std::endl;
  delete this->brain;
}

std::string Dog::getType() const { return this->type; }

Brain &Dog::getBrain() { return *this->brain; }

void Dog::makeSound() const { std::cout << "Woof" << std::endl; }
