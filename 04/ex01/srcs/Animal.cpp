#include "Animal.hpp"

Animal::Animal() : type( "Animal" ) {
  std::cout << this->type << " default constructor called" << std::endl;
}

Animal::Animal( const Animal &a ) {
  *this = a;
  std::cout << this->type << " copy constructor called" << std::endl;
}

Animal::~Animal() {
  std::cout << this->type << " default destructor called" << std::endl;
}

Animal &Animal::operator=( const Animal &a ) {
  this->type = a.type;
  std::cout << this->type << " = operator overload called" << std::endl;
  return *this;
}

std::string Animal::getType() const { return type; }

void Animal::makeSound() const {
  std::cout << this->type << " makes a generic sound" << std::endl;
}
