#pragma once

#include <iostream>

#include "Animal.hpp"

class Cat : public Animal {
 private:
 protected:
  std::string type;

 public:
  Cat();
  virtual ~Cat();
  virtual void makeSound() const;
};
