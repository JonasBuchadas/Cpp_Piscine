#pragma once
#ifndef __DOG_HPP__
#define __DOG_HPP__

#include <iostream>

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
 private:
  Brain* brain;

 public:
  Dog();
  virtual ~Dog();

  Dog( const Dog& src );

  Dog&   operator=( const Dog& src );
  void   makeSound() const;
  Brain& getBrain();
};

#endif
