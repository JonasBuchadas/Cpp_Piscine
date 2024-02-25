#include "AAnimal.hpp"

AAnimal::AAnimal() : type( "Animal" ) {
  std::cout << this->type << " default constructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal &a ) {
  *this = a;
  std::cout << this->type << " copy constructor called" << std::endl;
}

AAnimal::~AAnimal() {
  std::cout << this->type << " default destructor called" << std::endl;
}

AAnimal &AAnimal::operator=( const AAnimal &a ) {
  this->type = a.type;
  std::cout << this->type << " = operator overload called" << std::endl;
  return *this;
}

std::string AAnimal::getType() const { return this->type; }
