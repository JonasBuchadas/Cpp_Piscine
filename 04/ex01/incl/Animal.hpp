#pragma once
#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>

class Animal {
 private:
 protected:
  std::string type;

 public:
  Animal();
  virtual ~Animal();
  Animal(const Animal &src);

  Animal &operator=(const Animal &src);

  virtual void makeSound() const;
  std::string  getType() const;
};

#endif
