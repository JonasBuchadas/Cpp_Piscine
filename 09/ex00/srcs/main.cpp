#include "BitcoinExchange.hpp"

int main( int argc, char **argv ) {
  if ( argc != 2 ) {
    std::cout << "Error: could not open file" << std::endl;
    return ( 1 );
  }
  std::string filename = "data.csv";
  try {
    BitcoinExchange exchange( filename );
    filename = argv[1];
    exchange.readFile( filename );
  } catch ( std::exception &e ) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  return ( 0 );
}
