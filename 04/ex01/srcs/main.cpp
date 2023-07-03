#include "ex01.hpp"

int main (void)
{
	// const Animal* animals[SIZE];
	const Dog* d = new Dog();
	const Animal* c = new Cat();
	const Animal* d1 = new Dog (*d);

	delete d;
	delete d1;

	delete c;

	const Brain* b1 = new Brain();
	const Brain* b2 = new Brain(*b1);

	std::cout << b2->ideas[0] << std::endl;
	delete b1;
	delete b2;
/*
	int i = -1;
	while (++i < (SIZE / 2))
		animals[i] = new Dog();
	i--;
	while (++i < SIZE)
		animals[i] = new Cat();

	i = -1;
	while (++i < SIZE)
		delete animals[i];
*/
	return 0;
}
