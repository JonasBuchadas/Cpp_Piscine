#include "FragTrap.hpp"

#include "ClapTrap.hpp"

FragTrap::FragTrap() {
  std::cout << "Standard FragTrap Constructor called" << std::endl;
  this->name          = "";
  this->hit_points    = 100;
  this->attack_damage = 30;
  this->energy_points = 100;
}

FragTrap::FragTrap( std::string name ) {
  std::cout << "FragTrap Constructor called" << std::endl;
  this->name          = name;
  this->hit_points    = 100;
  this->attack_damage = 30;
  this->energy_points = 100;
}

FragTrap::FragTrap( const FragTrap &src ) : ClapTrap( src ) {
  std::cout << "FragTrap Copy Constructor called" << std::endl;
  *this = src;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap &FragTrap::operator=( const FragTrap &src ) {
  std::cout << "FragTrap Equal operator called" << std::endl;
  if ( this == &src )
    return ( *this );
  ClapTrap::operator=( src );
  return ( *this );
}

void FragTrap::highFivesGuys() {
  if ( this->energy_points <= 0 || this->hit_points <= 0 )
    std::cout << "FragTrap " << this->name << " is unable to high five guys" << std::endl;
  else {
    this->energy_points--;
    std::cout << "FragTrap " << this->name << " is now in high five mode" << std::endl;
  }
}
