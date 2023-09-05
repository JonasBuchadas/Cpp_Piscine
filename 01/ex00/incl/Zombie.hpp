#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <cstdio>
#include <iostream>

class Zombie {
 private:
  std::string _name;

 public:
  Zombie(std::string name);
  ~Zombie();
  void announce();
};

void    randowChump(std::string name);
Zombie *newZombie(std::string name);

#endif
