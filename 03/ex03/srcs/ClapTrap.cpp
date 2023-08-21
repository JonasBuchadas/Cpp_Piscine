#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
  std::cout << "Standard ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
  std::cout << "ClapTrap Constructor called" << std::endl;
  this->_name = name;
  this->attack_damage = defaultAttackDamage();
  this->hit_points = defaultHitPoints();
  this->energy_points = defaultEnergyPoints();
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap Destructor called" << std::endl;
}

int ClapTrap::defaultHitPoints(void) { return (10); }

int ClapTrap::defaultAttackDamage(void) { return (0); }

int ClapTrap::defaultEnergyPoints(void) { return (10); }

void ClapTrap::setName(std::string name) { this->_name = name; }

void ClapTrap::setHitPoints(int ammount) { this->hit_points = ammount; }

void ClapTrap::setAttackDamage(int ammount) { this->attack_damage = ammount; }

void ClapTrap::setEnergyPoints(int ammount) { this->energy_points = ammount; }

std::string ClapTrap::getName(void) { return (this->_name); }

int ClapTrap::getHitPoints(void) { return (this->hit_points); }

int ClapTrap::getEnergyPoints(void) { return (this->energy_points); }

int ClapTrap::getAttackDamage(void) { return (this->attack_damage); }

void ClapTrap::attack(const std::string &target) {
  if (this->energy_points <= 0 || this->hit_points <= 0)
    std::cout << "ClapTrap is unable to attack" << std::endl;
  else {
    this->energy_points--;
    std::cout << "ClapTrap " << this->_name << " attacks " << target
              << ", causing " << this->attack_damage << " point of damage"
              << std::endl;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->energy_points <= 0 || this->hit_points <= 0)
    std::cout << "ClapTrap is unable to repair" << std::endl;
  else {
    this->energy_points--;
    std::cout << "ClapTrap " << this->_name << " is repaired and receives "
              << amount << " hit points" << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  this->hit_points -= amount;
  std::cout << "ClapTrap " << this->_name << " was attacked and loses "
            << amount << " hit points" << std::endl;
}
