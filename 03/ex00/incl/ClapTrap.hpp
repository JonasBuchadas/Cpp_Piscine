#pragma once
#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <iostream>

class ClapTrap {
 private:
  std::string name;
  int         hit_points;
  int         energy_points;
  int         attack_damage;

 public:
  ClapTrap();
  ClapTrap(std::string name);
  ~ClapTrap();
  void        setName(std::string name);
  void        setHitPoints(int ammout);
  void        setAttackDamage(int ammout);
  void        setEnergyPoints(int ammout);
  std::string getName(void);
  int         getHitPoints(void);
  int         getAttackDamage(void);
  int         getEnergyPoints(void);
  void        attack(const std::string &target);
  void        takeDamage(unsigned int amount);
  void        beRepaired(unsigned int amount);
};

#endif
