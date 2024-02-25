#include "Cat.hpp"

Cat::Cat() : type( "Cat" ) {
  std::cout << this->type << " default constructor called" << std::endl;
}

Cat::~Cat() {
  std::cout << this->type << " default destructor called" << std::endl;
}

Cat::Cat( const Cat &src ) : Animal() {
  std::cout << this->type << " copy constructor called" << std::endl;
  *this = src;
}

Cat &Cat::operator=( const Cat &src ) {
  std::cout << this->type << " = operator called" << std::endl;
  if ( this == &src )
    return ( *this );
  this->type = src.type;
  return ( *this );
}

void Cat::makeSound() const { std::cout << "Meow" << std::endl; }
