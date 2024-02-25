#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
  std::cout << "Standard ClapTrap Constructor called" << std::endl;
  this->name          = "";
  this->attack_damage = 0;
  this->hit_points    = 10;
  this->energy_points = 10;
}

ClapTrap::ClapTrap( std::string name ) {
  std::cout << "ClapTrap Constructor called" << std::endl;
  this->name          = name;
  this->attack_damage = 0;
  this->hit_points    = 10;
  this->energy_points = 10;
}

ClapTrap::ClapTrap( const ClapTrap &src ) {
  std::cout << "ClapTrap Copy Constructor called" << std::endl;
  *this = src;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=( const ClapTrap &src ) {
  std::cout << "ClapTrap Equal operator called" << std::endl;
  if ( this == &src )
    return ( *this );
  this->name          = src.name;
  this->attack_damage = src.attack_damage;
  this->hit_points    = src.hit_points;
  this->energy_points = src.energy_points;
  return ( *this );
}

void ClapTrap::attack( const std::string &target ) {
  if ( this->energy_points <= 0 || this->hit_points <= 0 )
    std::cout << "ClapTrap is unable to attack" << std::endl;
  else {
    this->energy_points--;
    std::cout << "ClapTrap " << this->name << " attacks " << target
              << ", causing " << this->attack_damage << " point of damage"
              << std::endl;
  }
}

void ClapTrap::beRepaired( unsigned int amount ) {
  if ( this->energy_points <= 0 || this->hit_points <= 0 )
    std::cout << "ClapTrap is unable to repair" << std::endl;
  else {
    this->energy_points--;
    std::cout << "ClapTrap " << this->name << " is repaired and receives "
              << amount << " hit points" << std::endl;
  }
}

void ClapTrap::takeDamage( unsigned int amount ) {
  this->hit_points -= amount;
  std::cout << "ClapTrap " << this->name << " was attacked and loses " << amount
            << " hit points" << std::endl;
}

void ClapTrap::setName( std::string name ) { this->name = name; }

void ClapTrap::setHitPoints( int ammount ) { this->hit_points = ammount; }

void ClapTrap::setAttackDamage( int ammount ) { this->attack_damage = ammount; }

void ClapTrap::setEnergyPoints( int ammount ) { this->energy_points = ammount; }

std::string ClapTrap::getName( void ) { return ( this->name ); }

int ClapTrap::getHitPoints( void ) { return ( this->hit_points ); }

int ClapTrap::getEnergyPoints( void ) { return ( this->energy_points ); }

int ClapTrap::getAttackDamage( void ) { return ( this->attack_damage ); }
