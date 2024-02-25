#pragma once
#ifndef __WRONG_CAT_HPP__
#define __WRONG_CAT_HPP__

#include <iostream>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 private:
 protected:
  std::string type;

 public:
  WrongCat();
  ~WrongCat();
  WrongCat( const WrongCat &src );

  WrongCat &operator=( const WrongCat &src );
  void      makeSound() const;
};

#endif
