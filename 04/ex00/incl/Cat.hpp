#pragma once
#ifndef __CAT_HPP__
#define __CAT_HPP__

#include <iostream>

#include "Animal.hpp"

class Cat : public Animal {
 private:
 protected:
  std::string type;

 public:
  Cat();
  virtual ~Cat();
  Cat( const Cat &src );

  Cat &operator=( const Cat &src );
  void makeSound() const;
};

#endif
