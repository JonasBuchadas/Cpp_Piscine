#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
  std::cout << this->type << " default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << this->type << " default destructor called" << std::endl;
}

std::string WrongAnimal::getType() const { return type; }

void WrongAnimal::makeSound() const {
  std::cout << this->type << " makes a generic sound" << std::endl;
}
