#include "Cat.hpp"

Cat::Cat() : type("Cat") {
  std::cout << this->type << " default constructor called" << std::endl;
  this->brain = new Brain();
}

Cat::Cat(const Cat &c) : Animal(c) {
  //   this->type = c.type;
  if (c.brain)
    this->brain = new Brain(*c.brain);
  else
    this->brain = NULL;
  std::cout << this->type << " copy constructor called" << std::endl;
  *this = c;
}

Cat &Cat::operator=(const Cat &c) {
  std::cout << this->type << " = operator overload called" << std::endl;
  if (this == &c)
    return *this;
  Animal::operator=(c);
  //   this->type = d.type;
  if (this->brain)
    delete this->brain;
  if (c.brain)
    this->brain = new Brain(*c.brain);
  else
    this->brain = NULL;
  //   *brain     = *d.brain;
  return *this;
}

Cat::~Cat() {
  std::cout << this->type << " default destructor called" << std::endl;
  delete this->brain;
}

std::string Cat::getType() const { return this->type; }

Brain &Cat::getBrain() { return *this->brain; }

void Cat::makeSound() const { std::cout << "Meow" << std::endl; }
