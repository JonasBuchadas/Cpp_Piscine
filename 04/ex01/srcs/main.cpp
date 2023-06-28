#include "ex01.hpp"

int main (void)
{
	const Animal* animals[SIZE];
	const Animal* d = new Dog();
	const Animal* c = new Cat();

	delete d;
	delete c;

	int i = -1;
	while (++i < (SIZE / 2))
		animals[i] = new Dog();
	i--;
	while (++i < SIZE)
		animals[i] = new Cat();

	i = -1;
	while (++i < SIZE)
		delete animals[i];
	return 0;
}
