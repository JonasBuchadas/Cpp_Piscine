#include "Weird.hpp"

int main(void) {
  DiamondTrap c = DiamondTrap("Diamond");
  c.attack("bear");
  c.takeDamage(40);
  c.beRepaired(2);
  c.whoAmI();
  c.guardGate();
  return 0;
}
