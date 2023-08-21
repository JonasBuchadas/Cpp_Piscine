#include <iostream>

int main(void) {
  std::string str = "HI THIS IS BRAIN";
  std::string *stringPTR = &str;
  std::string &stringREF = str;

  std::cout << "Memory address:\t\t" << &str << "\nPTR Memory Adress:\t"
            << stringPTR << "\nREF Memory Address:\t" << &stringREF
            << std::endl;
  std::cout << "Value:\t\t" << str << "\nPTR Value:\t" << *stringPTR
            << "\nREF Value:\t" << stringREF << std::endl;
}
