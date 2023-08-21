#pragma once

#include <iostream>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 private:
 protected:
  std::string type;

 public:
  WrongCat();
  ~WrongCat();
  void makeSound() const;
};
