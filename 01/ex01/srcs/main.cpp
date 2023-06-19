#include "Zombie.hpp"

int main (void) {
	Zombie *horde;

	horde = zombieHorde(4, "Gnu");
	for (int i = 0; i < 4; i++)
	{
		horde[i].announce();
	}
	delete []horde;
}
