#include "Dog.hpp"

Dog::Dog() : type("Dog") {
  std::cout << this->type << " default constructor called" << std::endl;
  this->brain = new Brain();
}

Dog::Dog(const Dog &d) : Animal(d) {
  this->type = d.type;
  std::cout << this->type << " copy constructor called" << std::endl;
  if (d.brain)
    this->brain = new Brain(*d.brain);
  else
    this->brain = NULL;
}

Dog &Dog::operator=(const Dog &d) {
  std::cout << this->type << " = operator overload called" << std::endl;
  if (this == &d)
    return *this;
  Animal::operator=(d);
  if (this->brain)
    delete this->brain;
  if (d.brain)
    this->brain = new Brain(*d.brain);
  else
    this->brain = NULL;
  return *this;
}

Dog::~Dog() {
  std::cout << this->type << " default destructor called" << std::endl;
  delete this->brain;
}

std::string Dog::getType() const { return this->type; }

Brain &Dog::getBrain() { return *this->brain; }

void Dog::makeSound() const { std::cout << "Woof" << std::endl; }
