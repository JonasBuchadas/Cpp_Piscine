#include <ScalarConverter.hpp>

long double ScalarConverter::n = 0;
// int			ScalarConverter::i = 0;
// char 		ScalarConverter::c = '\0';
// float 		ScalarConverter::f = 0.0f;
// double 		ScalarConverter::d = 0.0;

void ScalarConverter::display() {
  printChar();
  printInt();
  printFloat();
  printDouble();
}

void ScalarConverter::printChar() {
  std::cout << "char: ";
  if (ScalarConverter::n < CHAR_MIN || ScalarConverter::n > CHAR_MAX) {
    std::cout << "impossible" << std::endl;
    return;
  }
  char c = (char)ScalarConverter::n;
  if (!isprint(c)) {
    std::cout << "non displayable" << std::endl;
    return;
  }
  std::cout << "'" << c << "'" << std::endl;
}

void ScalarConverter::printInt() {
  std::cout << "int: ";
  if (ScalarConverter::n < INT_MIN || ScalarConverter::n > INT_MAX) {
    std::cout << "impossible" << std::endl;
    return;
  }
  int i = (int)ScalarConverter::n;
  std::cout << i << std::endl;
}

void ScalarConverter::printFloat() {
  std::cout << "float: ";
  if (ScalarConverter::n < FLT_MIN || ScalarConverter::n > FLT_MAX) {
    std::cout << "impossible" << std::endl;
    return;
  }
  float f = (float)ScalarConverter::n;
  std::cout << f << std::endl;
}

void ScalarConverter::printDouble() {
  std::cout << "double: ";
  if (ScalarConverter::n < DBL_MIN || ScalarConverter::n > DBL_MAX) {
    std::cout << "impossible" << std::endl;
    return;
  }
  double d = (double)ScalarConverter::n;
  std::cout << d << std::endl;
}

void ScalarConverter::convert(char *str) {
  char *end;
  // ScalarConverter::n = atol(str);
  // std::string::size_type sz;
  double d = strtod(str, &end);
  std::cout << "str:\t" << d << std::endl;
  std::cout << "end:\t" << end << std::endl;
  // display();
}
