#include "repetitive_work.hpp"

int main (void)
{
	FragTrap c = FragTrap("Trap");
	c.attack("bear");
	c.takeDamage(50);
	c.beRepaired(2);
	c.highFivesGuys();
	return 0;
}
