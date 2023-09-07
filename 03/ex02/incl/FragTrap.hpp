#pragma once
#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include <iostream>

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
 private:
 public:
  FragTrap(std::string name);
  ~FragTrap();
  FragTrap(const FragTrap &src);

  FragTrap &operator=(const FragTrap &src);
  void      highFivesGuys(void);
};

#endif
