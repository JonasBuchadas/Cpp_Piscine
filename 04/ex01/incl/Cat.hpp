#pragma once
#ifndef __CAT_HPP__
#define __CAT_HPP__

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 private:
  Brain* brain;

 public:
  Cat();
  virtual ~Cat();

  Cat( const Cat& src );

  Cat&   operator=( const Cat& src );
  void   makeSound() const;
  Brain& getBrain();
};

#endif
