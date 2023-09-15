#include "Ex03.hpp"

int main() {
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter* me = new Character("me");
  AMateria*   tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  me->unequip(0);
  AMateria* f1 = AMateria::floor[0];
  bob->equip(f1);
  me->equip(f1);
  bob->use(0, *me);
  delete bob;
  delete me;
  delete src;
  return 0;
}
