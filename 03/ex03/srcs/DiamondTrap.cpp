#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap() {
  std::cout << "DiamondTrap Constructor called" << std::endl;
  this->_name = name;
  setHitPoints(defaultHitPoints());
  setAttackDamage(defaultAttackDamage());
  setEnergyPoints(defaultEnergyPoints());
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(), ScavTrap(), FragTrap() {
  std::cout << "DiamondTrap Copy Constructor called" << std::endl;
  *this = src;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src) {
  std::cout << "DiamondTrap Equal operator called" << std::endl;
  if (this == &src)
    return (*this);
  this->name          = src.name;
  this->attack_damage = src.attack_damage;
  this->hit_points    = src.hit_points;
  this->energy_points = src.energy_points;
  return (*this);
}

void DiamondTrap::whoAmI() {
  if (getEnergyPoints() <= 0 || getHitPoints() <= 0)
    std::cout << "DiamondTrap is unable to speak" << std::endl;
  else {
    std::cout << "DiamondTrap name is :\t" << _name << std::endl;
    std::cout << "ClapTrap name is :\t" << getName() << std::endl;
  }
}
