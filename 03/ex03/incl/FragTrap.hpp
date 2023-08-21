#pragma once
#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include <iostream>

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
 private:
 public:
  FragTrap();
  FragTrap(std::string name);
  ~FragTrap();
  static int defaultHitPoints(void);
  static int defaultAttackDamage(void);
  static int defaultEnergyPoints(void);
  void attack(const std::string &target);
  void highFivesGuys(void);
};

#endif
