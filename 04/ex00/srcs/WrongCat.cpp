#include "WrongCat.hpp"

WrongCat::WrongCat() : type( "WrongCat" ) {
  std::cout << this->type << " default constructor called" << std::endl;
}

WrongCat::~WrongCat() {
  std::cout << this->type << " default destructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat &src ) : WrongAnimal() {
  std::cout << this->type << " copy constructor called" << std::endl;
  *this = src;
}

WrongCat &WrongCat::operator=( const WrongCat &src ) {
  std::cout << this->type << " = operator called" << std::endl;
  if ( this == &src )
    return ( *this );
  this->type = src.type;
  return ( *this );
}

void WrongCat::makeSound() const { std::cout << "Meow" << std::endl; }
