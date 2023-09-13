#pragma once
#ifndef __DOG_HPP__
#define __DOG_HPP__

#include <iostream>

#include "Animal.hpp"

class Dog : public Animal {
 private:
 protected:
  std::string type;

 public:
  Dog();
  virtual ~Dog();
  Dog(const Dog &src);

  Dog &operator=(const Dog &src);
  void makeSound() const;
};

#endif
