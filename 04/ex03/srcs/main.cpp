#include "recap.hpp"

int main (void)
{
	AMateria* ice = new Ice();
	ICharacter* j = new Character("Jonas");
	ICharacter* s = new Character("Sara");

	std::cout << ice->getType() << std::endl;
	j->equip(ice);
	j->use(0, *s);
	j->unequip(0);
	s->equip(ice);
	s->use(0, *j);
	delete ice;
	delete j;
	delete s;
	return 0;
}
