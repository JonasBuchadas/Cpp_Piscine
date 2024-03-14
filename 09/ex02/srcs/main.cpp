#include "PmergeMe.hpp"

int main( int ac, char** av ) {
  if ( ac == 1 ) {
    std::cout << "Error: not given any number" << std::endl;
    return ( 1 );
  }

  if ( isSorted( av ) )
    return ( 1 );

  try {
    PmergeMe pmergeMe( av );
    pmergeMe.sort();
  } catch ( std::exception& e ) {
    std::cout << "Error: " << e.what() << std::endl;
    return ( 1 );
  }
  return ( 0 );
}

int isSorted( char** av ) {
  for ( int i = 1; av[i + 1]; i++ ) {
    if ( std::atoi( av[i] ) > std::atoi( av[i + 1] ) )
      return ( 0 );
  }
  std::cout << "Already sorted!" << std::endl;
  return ( 1 );
}
