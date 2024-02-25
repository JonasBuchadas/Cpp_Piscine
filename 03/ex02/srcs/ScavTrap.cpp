#include "ScavTrap.hpp"

#include "ClapTrap.hpp"

ScavTrap::ScavTrap() {
  std::cout << "Standard ScavTrap Constructor called" << std::endl;
  this->name          = "";
  this->hit_points    = 100;
  this->attack_damage = 20;
  this->energy_points = 50;
}

ScavTrap::ScavTrap( std::string name ) {
  std::cout << "ScavTrap Constructor called" << std::endl;
  this->name          = name;
  this->hit_points    = 100;
  this->attack_damage = 20;
  this->energy_points = 50;
}

ScavTrap::ScavTrap( const ScavTrap &src ) : ClapTrap( src ) {
  std::cout << "ScavTrap Copy Constructor called" << std::endl;
  *this = src;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=( const ScavTrap &src ) {
  std::cout << "ScavTrap Equal operator called" << std::endl;
  if ( this == &src )
    return ( *this );
  ClapTrap::operator=( src );
  return ( *this );
}

void ScavTrap::guardGate() {
  if ( this->energy_points <= 0 || this->hit_points <= 0 )
    std::cout << "ScavTrap " << this->name << " is unable to enter Gate keeper mode" << std::endl;
  else {
    this->energy_points--;
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
  }
}
