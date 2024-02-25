#include "AMateria.hpp"

AMateria **AMateria::floor = NULL;

AMateria::AMateria( std::string &type ) : type( type ) {
  this->equipped = false;
  this->usages   = 0;
  std::cout << this->type << " default constructor called" << std::endl;
}

AMateria::AMateria( const AMateria &src ) : type( src.type ) {
  std::cout << "Materia copy destructor called" << std::endl;
  *this = src;
}

AMateria::~AMateria() {
  std::cout << "Materia default destructor called" << std::endl;
}

std::string const &AMateria::getType() const { return this->type; }

int AMateria::getUsages() { return this->usages; }

bool AMateria::getEquipped() { return this->equipped; }

void AMateria::setEquipped( bool equip ) { this->equipped = equip; }

AMateria &AMateria::operator=( const AMateria &src ) {
  if ( this == &src ) {
    return ( *this );
  }
  this->equipped = false;
  this->usages   = src.usages;
  return ( *this );
}

void AMateria::drop() {
  AMateria **list;
  int        i = 0;
  while ( floor != NULL && floor[i] != NULL )
    if ( floor[i++] == this )
      return;
  list        = new AMateria *[i + 2];
  list[i + 1] = NULL;
  list[i]     = this;
  for ( int j = 0; j < i; j++ )
    list[j] = floor[j];
  delete ( floor );
  floor = list;
}

void AMateria::use( ICharacter &target ) {
  this->usages++;
  std::cout << this->type << " has been used on " << target.getName()
            << std::endl;
}
