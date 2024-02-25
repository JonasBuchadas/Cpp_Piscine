#pragma once

#include <ICharacter.hpp>
#include <iostream>

class ICharacter;

class AMateria {
 private:
  int  usages;
  bool equipped;

 protected:
  std::string& type;

 public:
  static AMateria** floor;
  AMateria( std::string& type );
  AMateria( const AMateria& src );
  virtual ~AMateria();

  AMateria& operator=( const AMateria& src );

  std::string const& getType() const;

  int  getUsages();
  bool getEquipped();
  void setEquipped( bool equip );
  void drop();

  virtual AMateria* clone() const = 0;
  virtual void      use( ICharacter& target );
};
