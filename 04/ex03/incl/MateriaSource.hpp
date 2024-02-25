#pragma once

#include <AMateria.hpp>
#include <IMateriaSource.hpp>

class MateriaSource : public IMateriaSource {
 private:
  static const int materia_size = 4;
  AMateria        *inventory[materia_size];

 public:
  MateriaSource();
  MateriaSource( const MateriaSource &src );
  MateriaSource &operator=( const MateriaSource &src );
  virtual ~MateriaSource();

  void      learnMateria( AMateria      *);
  AMateria *createMateria( std::string const &type );
};
