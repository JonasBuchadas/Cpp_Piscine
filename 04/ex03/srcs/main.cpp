#include "recap.hpp"

int main (void)
{
	AMateria* ice = new Ice();
	ICharacter* j = new Character("Jonas");

	std::cout << ice->getType() << std::endl;
	j->equip(ice);
	ICharacter* s = new Character("Sara");
	j->use(1, *s);
	s->equip(ice);
	s->use(1, *j);
	delete j;
	delete s;
	return 0;
}
