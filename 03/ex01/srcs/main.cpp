#include "serena_my_love.hpp"

int main( void ) {
  ScavTrap c = ScavTrap( "Trap" );
  c.attack( "bear" );
  c.takeDamage( 99 );
  ScavTrap c1 = ScavTrap( c );
  c.beRepaired( 2 );
  c.guardGate();
  c1.guardGate();
  return 0;
}
