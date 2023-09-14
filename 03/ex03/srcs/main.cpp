#include "DiamondTrap.hpp"
#include "Weird.hpp"

int main(void) {
  DiamondTrap c = DiamondTrap("Diamond");
  DiamondTrap d(c);
  DiamondTrap e;
  e = c;
  e.guardGate();
  e.whoAmI();
  e.guardGate();
  e.highFivesGuys();
  c.attack("bear");
  c.takeDamage(40);
  c.beRepaired(2);
  c.whoAmI();
  c.guardGate();
  return 0;
}
