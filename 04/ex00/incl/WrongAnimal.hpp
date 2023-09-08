#pragma once
#ifndef __WRONG_ANIMAL_HPP__
#define __WRONG_ANIMAL_HPP__

#include <iostream>

class WrongAnimal {
 private:
 protected:
  std::string type;

 public:
  WrongAnimal();
  ~WrongAnimal();
  WrongAnimal(const WrongAnimal &src);

  WrongAnimal &operator=(const WrongAnimal &src);
  void         makeSound() const;
  std::string  getType() const;
};

#endif
