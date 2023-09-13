#pragma once
#ifndef __AANIMAL_HPP__
#define __AANIMAL_HPP__

#include <iostream>

class AAnimal {
 private:
 protected:
  std::string type;

 public:
  AAnimal();
  virtual ~AAnimal();
  AAnimal(const AAnimal& a);

  AAnimal& operator=(const AAnimal& a);

  virtual void makeSound() const = 0;
  std::string  getType() const;
};

#endif
