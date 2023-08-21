#pragma once

#include <AMateria.hpp>
#include <ICharacter.hpp>
#include <iostream>

class Ice : public AMateria {
 private:
  static std::string _type;

 public:
  Ice();
  Ice(const Ice& i);
  ~Ice();

  Ice& operator=(const Ice& i);

  virtual AMateria* clone() const;
  virtual void use(ICharacter& target);
};
