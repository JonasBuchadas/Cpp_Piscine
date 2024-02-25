#include "Harl.hpp"

int main( int ac, char **av ) {
  Harl harl = Harl();

  if ( ac == 1 )
    std::cout << "Harl is not complaining now" << std::endl;
  else
    harl.complain( av[1] );
  return ( 0 );
}
