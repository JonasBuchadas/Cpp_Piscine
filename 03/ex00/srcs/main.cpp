#include "and_open.hpp"

int main( void ) {
  ClapTrap c = ClapTrap( "Trap" );
  c.attack( "bear" );
  c.takeDamage( 3 );
  c.beRepaired( 2 );
  return 0;
}
