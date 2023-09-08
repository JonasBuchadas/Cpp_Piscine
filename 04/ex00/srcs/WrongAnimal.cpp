#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
  std::cout << this->type << " default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << this->type << " default destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
  std::cout << this->type << " copy constructor called" << std::endl;
  *this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src) {
  std::cout << this->type << " = operator called" << std::endl;
  if (this == &src)
    return (*this);
  this->type = src.type;
  return (*this);
}

std::string WrongAnimal::getType() const { return type; }

void WrongAnimal::makeSound() const {
  std::cout << this->type << " makes a generic sound" << std::endl;
}
