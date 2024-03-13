#include <cstring>
#include <stdexcept>
#include <string>

#include "RPN.hpp"

int main( int argc, char** argv ) {
  if ( argc != 2 ) {
    std::cout << "Error: no input given" << std::endl;
    return ( 1 );
  }
  RPN         calculator;
  std::string input( argv[1] );
  try {
    calculator.calculate( input );
  } catch ( std::exception& e ) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  return ( 0 );
}
