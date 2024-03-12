#include <vector>

#include "Span.hpp"

int main() {
  try {
    Span sp = Span( 5 );
    sp.addNumber( 6 );
    sp.addNumber( 3 );
    sp.addNumber( 17 );
    sp.addNumber( 11 );
    sp.addNumber( 11 );
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    int              arr[] = { 12, 21, 3, 42, 5, 666, 77, 81, 90, 10 };
    std::vector<int> vect( arr, arr + sizeof( arr ) / sizeof( int ) );
    Span             sp1 = Span( 10 );
    sp1.addNumbers( vect );
    std::cout << sp1.shortestSpan() << std::endl;
    std::cout << sp1.longestSpan() << std::endl;
    Span sp2 = Span( 10 );
    sp2.addNumber( 2 );
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
    return 0;
  } catch ( const std::exception& e ) {
    std::cerr << e.what() << std::endl;
  }
}
