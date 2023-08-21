#include "Cat.hpp"

Cat::Cat() : type("Cat") {
  std::cout << this->type << " default constructor called" << std::endl;
}

Cat::~Cat() {
  std::cout << this->type << " default destructor called" << std::endl;
}

void Cat::makeSound() const { std::cout << "Meow" << std::endl; }
