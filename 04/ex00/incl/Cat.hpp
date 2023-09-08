#pragma once

#include <iostream>

#include "Animal.hpp"

class Cat : public Animal {
 private:
 protected:
  std::string type;

 public:
  Cat();
  virtual ~Cat();
  Cat(const Cat &src);

  Cat                &operator=(const Cat &src);
  virtual void        makeSound() const;
  virtual std::string getType() const;
};
