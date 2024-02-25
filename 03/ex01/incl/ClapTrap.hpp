#pragma once
#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <iostream>

class ClapTrap {
 protected:
  std::string name;
  int         hit_points;
  int         energy_points;
  int         attack_damage;

 public:
  ClapTrap();
  ClapTrap( std::string name );
  ClapTrap( const ClapTrap &src );
  ~ClapTrap();
  ClapTrap &operator=( const ClapTrap &src );

  void attack( const std::string &target );
  void takeDamage( unsigned int amount );
  void beRepaired( unsigned int amount );
};

#endif
