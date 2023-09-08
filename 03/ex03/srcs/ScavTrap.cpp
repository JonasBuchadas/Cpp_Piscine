#include "ScavTrap.hpp"

#include "ClapTrap.hpp"

ScavTrap::ScavTrap() {
  std::cout << "Standard ScavTrap Constructor called" << std::endl;
  this->name          = "";
  this->hit_points    = defaultHitPoints();
  this->attack_damage = defaultAttackDamage();
  this->energy_points = defaultEnergyPoints();
}

ScavTrap::ScavTrap(std::string name) {
  std::cout << "ScavTrap Constructor called" << std::endl;
  this->name          = name;
  this->hit_points    = defaultHitPoints();
  this->attack_damage = defaultAttackDamage();
  this->energy_points = defaultEnergyPoints();
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
  std::cout << "ScavTrap Copy Constructor called" << std::endl;
  *this = src;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src) {
  std::cout << "ScavTrap Equal operator called" << std::endl;
  if (this == &src)
    return (*this);
  this->name          = src.name;
  this->hit_points    = src.hit_points;
  this->attack_damage = src.attack_damage;
  this->energy_points = src.energy_points;
  return (*this);
}

int ScavTrap::defaultHitPoints(void) { return (100); }

int ScavTrap::defaultAttackDamage(void) { return (20); }

int ScavTrap::defaultEnergyPoints(void) { return (50); }

void ScavTrap::guardGate() {
  if (this->energy_points <= 0 || this->hit_points <= 0)
    std::cout << "ScavTrap is unable to enter Gate keeper mode" << std::endl;
  else {
    this->energy_points--;
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
  }
}
