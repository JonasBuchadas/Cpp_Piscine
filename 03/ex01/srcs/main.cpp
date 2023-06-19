#include "serena_my_love.hpp"

int main (void)
{
	ScavTrap c = ScavTrap("Trap");
	c.attack("bear");
	c.takeDamage(100);
	c.beRepaired(2);
	c.guardGate();
	return 0;
}
