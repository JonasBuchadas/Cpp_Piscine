#include "AMateria.hpp"

AMateria::AMateria(std::string &type) : type(type) {
  this->equipped = false;
  this->usages   = 0;
  std::cout << this->type << " default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &src) : type(src.type) {
  std::cout << "Materia copy destructor called" << std::endl;
  *this = src;
}

AMateria::~AMateria() {
  std::cout << "Materia default destructor called" << std::endl;
}

std::string const &AMateria::getType() const { return this->type; }

int AMateria::getUsages() { return this->usages; }

bool AMateria::getEquipped() { return this->equipped; }

void AMateria::setEquipped(bool equip) { this->equipped = equip; }

AMateria &AMateria::operator=(const AMateria &src) {
  if (this == &src) {
    return (*this);
  }
  this->equipped = false;
  this->usages   = src.usages;
  this->type     = src.type;
  return (*this);
}

void AMateria::use(ICharacter &target) {
  this->usages++;
  std::cout << this->type << " has been used on " << target.getName()
            << std::endl;
}
