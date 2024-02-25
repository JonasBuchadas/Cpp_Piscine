#include "Ex00.hpp"

int main( void ) {
  Bureaucrat s = Bureaucrat( "Sara", 1 );
  std::cout << s;
  try {
    Bureaucrat j = Bureaucrat( "Jonas", 151 );
    j.incrementGrade();
    std::cout << j;
    s.incrementGrade();
  } catch ( const std::exception& e ) {
    std::cout << e.what() << std::endl;
  }
}
