#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap( "_clap_name" ), ScavTrap( "_clap_name" ), FragTrap( "_clap_name" ) {
  std::cout << "Standard DiamondTrap Constructor called" << std::endl;
  this->name = "";
  setHitPoints( defaultHitPoints() );
  setAttackDamage( defaultAttackDamage() );
  setEnergyPoints( defaultEnergyPoints() );
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name + "_clap_name" ), ScavTrap( name + "_clap_name" ), FragTrap( name + "_clap_name" ) {
  std::cout << "DiamondTrap Constructor called" << std::endl;
  this->name = name;
  setHitPoints( defaultHitPoints() );
  setAttackDamage( defaultAttackDamage() );
  setEnergyPoints( defaultEnergyPoints() );
}

DiamondTrap::DiamondTrap( const DiamondTrap &src ) : ClapTrap(), ScavTrap(), FragTrap() {
  std::cout << "DiamondTrap Copy Constructor called" << std::endl;
  *this = src;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=( const DiamondTrap &src ) {
  std::cout << "DiamondTrap Equal operator called" << std::endl;
  if ( this == &src )
    return ( *this );
  this->name = src.name;
  ClapTrap::operator=( src );
  return ( *this );
}

void DiamondTrap::whoAmI() {
  if ( getEnergyPoints() <= 0 || getHitPoints() <= 0 )
    std::cout << "DiamondTrap is unable to speak" << std::endl;
  else {
    std::cout << "DiamondTrap name is :\t" << name << std::endl;
    std::cout << "ClapTrap name is :\t" << getName() << std::endl;
  }
}
