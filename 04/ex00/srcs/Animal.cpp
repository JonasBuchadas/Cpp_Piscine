#include "Animal.hpp"

Animal::Animal() : type("Animal") {
  std::cout << this->type << " default constructor called" << std::endl;
}

Animal::~Animal() {
  std::cout << this->type << " default destructor called" << std::endl;
}

std::string Animal::getType() const { return type; }

void Animal::makeSound() const {
  std::cout << this->type << " makes a generic sound" << std::endl;
}
