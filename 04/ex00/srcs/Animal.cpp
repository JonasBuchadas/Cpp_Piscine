#include "Animal.hpp"

Animal::Animal() : type( "Animal" ) {
  std::cout << this->type << " default constructor called" << std::endl;
}

Animal::~Animal() {
  std::cout << this->type << " default destructor called" << std::endl;
}

Animal::Animal( const Animal &src ) : type( src.type ) {
  std::cout << this->type << " copy constructor called" << std::endl;
  *this = src;
}

Animal &Animal::operator=( const Animal &src ) {
  std::cout << this->type << " = operator called" << std::endl;
  if ( this == &src )
    return ( *this );
  this->type = src.type;
  return ( *this );
}

std::string Animal::getType() const { return type; }

void Animal::makeSound() const {
  std::cout << this->type << " makes a generic sound" << std::endl;
}
