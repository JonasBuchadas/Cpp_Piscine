#pragma once
#ifndef __DOG_HPP__
#define __DOG_HPP__

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
 private:
  Brain* brain;

 public:
  Dog();
  virtual ~Dog();

  Dog(const Dog& src);

  Dog&                operator=(const Dog& src);
  virtual void        makeSound() const;
  Brain&              getBrain();
};

#endif
