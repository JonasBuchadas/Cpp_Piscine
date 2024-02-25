#include <iostream>

int main( void ) {
  std::string  str       = "HI THIS IS BRAIN";
  std::string *stringPTR = &str;
  std::string &stringREF = str;

  std::cout << "Memory address:\t\t" << &str << std::endl;
  std::cout << "PTR Memory Adress:\t" << stringPTR << std::endl;
  std::cout << "REF Memory Address:\t" << &stringREF << std::endl;
  std::cout << "Value:\t\t\t" << str << std::endl;
  std::cout << "PTR Value:\t\t" << *stringPTR << std::endl;
  std::cout << "REF Value:\t\t" << stringREF << std::endl;
}
