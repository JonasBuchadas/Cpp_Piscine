#include "Weird.hpp"

int main(void) {
  DiamondTrap c = DiamondTrap("Diamond");
  DiamondTrap d(c);
  DiamondTrap e;
  e.guardGate();
  e.whoAmI();
  c.attack("bear");
  c.takeDamage(40);
  c.beRepaired(2);
  c.whoAmI();
  c.guardGate();
  return 0;
}
