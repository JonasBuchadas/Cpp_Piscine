#include "Zombie.hpp"

int main( void ) {
  Zombie *horde;
  int     n = 4;

  horde = zombieHorde( n, "Gnu" );
  for ( int i = 0; i < n; i++ ) {
    horde[i].announce();
  }
  delete[] horde;
}
