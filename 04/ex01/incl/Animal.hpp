#pragma once

#include <iostream>

class Animal {
 private:
 protected:
  std::string type;

 public:
  Animal();
  Animal(const Animal& a);
  virtual ~Animal();

  Animal& operator=(const Animal& a);

  virtual void makeSound() const;
  std::string getType() const;
};
