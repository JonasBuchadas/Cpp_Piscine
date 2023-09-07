#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) {
  std::cout << "ScavTrap Constructor called" << std::endl;
  setName(name);
  setHitPoints(100);
  setAttackDamage(20);
  setEnergyPoints(50);
}

ScavTrap::ScavTrap(const ScavTrap &src) { *this = src; }

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src) {
  if (this == &src)
    return (*this);
  setEnergyPoints(src.getEnergyPoints());
  return (*this);
}

void ScavTrap::guardGate() {
  if (this->getEnergyPoints() <= 0 || this->getHitPoints() <= 0)
    std::cout << "ScavTrap is unable to enter Gate keeper mode" << std::endl;
  else {
    this->setEnergyPoints(this->getEnergyPoints() - 1);
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
  }
}
