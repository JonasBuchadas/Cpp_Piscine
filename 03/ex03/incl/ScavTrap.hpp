#pragma once
#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include <iostream>

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
 private:
 public:
  ScavTrap();
  ScavTrap(std::string name);
  ~ScavTrap();
  ScavTrap(const ScavTrap &src);

  static int defaultHitPoints(void);
  static int defaultAttackDamage(void);
  static int defaultEnergyPoints(void);

  ScavTrap &operator=(const ScavTrap &src);
  void      guardGate();
};

#endif
