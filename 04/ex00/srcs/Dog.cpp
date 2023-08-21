#include "Dog.hpp"

Dog::Dog() : type("Dog") {
  std::cout << this->type << " default constructor called" << std::endl;
}

Dog::~Dog() {
  std::cout << this->type << " default destructor called" << std::endl;
}

void Dog::makeSound() const { std::cout << "Woof" << std::endl; }
