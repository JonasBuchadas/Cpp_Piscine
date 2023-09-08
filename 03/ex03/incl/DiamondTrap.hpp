#pragma once
#ifndef __DIAMONDTRAP_HPP__
#define __DIAMONDTRAP_HPP__

#include <iostream>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
 private:
  std::string _name;

 public:
  DiamondTrap();
  DiamondTrap(std::string name);
  DiamondTrap(const DiamondTrap &src);
  ~DiamondTrap();
  DiamondTrap &operator=(const DiamondTrap &src);
  void whoAmI();
  using FragTrap::defaultAttackDamage;
  using FragTrap::defaultHitPoints;
  using ScavTrap::attack;
  using ScavTrap::defaultEnergyPoints;
};

#endif
