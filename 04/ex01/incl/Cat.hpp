#pragma once

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 private:
  Brain* brain;

 protected:
  std::string type;

 public:
  Cat();
  Cat(const Cat& c);
  virtual ~Cat();

  Cat& operator=(const Cat& c);

  std::string getType();
  Brain& getBrain();

  virtual void makeSound() const;
};
