#pragma once

#include <AMateria.hpp>
#include <ICharacter.hpp>
#include <iostream>

class Cure : public AMateria {
 private:
  static std::string _type;

 public:
  Cure();
  Cure(const Cure& i);
  ~Cure();

  Cure& operator=(const Cure& i);

  virtual AMateria* clone() const;
  virtual void use(ICharacter& target);
};
