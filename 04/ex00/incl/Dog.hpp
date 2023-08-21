#pragma once

#include <iostream>

#include "Animal.hpp"

class Dog : public Animal {
 private:
 protected:
  std::string type;

 public:
  Dog();
  virtual ~Dog();
  virtual void makeSound() const;
};
