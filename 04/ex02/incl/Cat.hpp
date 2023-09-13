#pragma once
#ifndef __CAT_HPP__
#define __CAT_HPP__

#include <iostream>

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
 private:
  Brain* brain;

 public:
  Cat();
  virtual ~Cat();

  Cat(const Cat& src);

  Cat&         operator=(const Cat& src);
  virtual void makeSound() const;
  Brain&       getBrain();
};

#endif
