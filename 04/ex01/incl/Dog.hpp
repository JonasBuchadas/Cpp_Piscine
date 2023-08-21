#pragma once

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
 private:
  Brain* brain;

 protected:
  std::string type;

 public:
  Dog();
  Dog(const Dog& d);
  virtual ~Dog();

  Dog& operator=(const Dog& c);

  std::string getType();
  Brain& getBrain();

  virtual void makeSound() const;
};
