#include "recap.hpp"

int main (void)
{
	AMateria* ice1 = new Ice();
	ICharacter* j = new Character("Jonas");

	j->equip(ice1);
	ICharacter* s = new Character("Sara");
	j->use(1, *s);
	AMateria* ice2 = ice1->clone();
	AMateria* ice3 = ice2->clone();
	s->equip(ice2);
	s->equip(ice3);
	s->use(1, *j);
	std::cout << "Materia Ice1 usage: " << ice1->getUsages() << std::endl;
	std::cout << "Materia Ice2 usage: " << ice2->getUsages() << std::endl;
	delete j;
	delete s;
	return 0;
}
