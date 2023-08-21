#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(std::string name) {
  std::cout << "ScavTrap Constructor called" << std::endl;
  setName(name);
  setHitPoints(defaultHitPoints());
  setAttackDamage(defaultAttackDamage());
  setEnergyPoints(defaultEnergyPoints());
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap Destructor called" << std::endl;
}

int ScavTrap::defaultHitPoints(void) { return (100); }

int ScavTrap::defaultAttackDamage(void) { return (20); }

int ScavTrap::defaultEnergyPoints(void) { return (50); }

void ScavTrap::attack(const std::string &target) {
  if (getEnergyPoints() <= 0 || getHitPoints() <= 0)
    std::cout << "ScavTrap is unable to attack" << std::endl;
  else {
    setEnergyPoints(getEnergyPoints() - 1);
    std::cout << "ScavTrap " << getName() << " attacks " << target
              << ", causing " << getAttackDamage() << " point of damage"
              << std::endl;
  }
}

void ScavTrap::guardGate() {
  if (this->getEnergyPoints() <= 0 || this->getHitPoints() <= 0)
    std::cout << "ScavTrap is unable to enter Gate keeper mode" << std::endl;
  else {
    this->setEnergyPoints(this->getEnergyPoints() - 1);
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
  }
}
