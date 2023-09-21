#include <ScalarConverter.hpp>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
  *this = src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) {
  if (this == &src)
    return *this;
  return *this;
}

void ScalarConverter::convert(char* str) {
  char*              end;
  double             d               = strtod(str, &end);
  const funcValPtr   enumValFunc[]   = {&isCastableToChar, &isCastableToInt, &isCastableToFloat};
  const funcPrintPtr enumPrintFunc[] = {&convertPrintChar, &convertPrintInt, &convertPrintFloat};

  d = convertMathConsts(d, str);
  for (int i = 0; i < 3; i++) {
    if (enumValFunc[i](d, end)) {
      enumPrintFunc[i](d);
      return;
    }
  }
  display(d);
}

double ScalarConverter::convertMathConsts(double d, char* str) {
  if (strcmp(str, "inf") == 0 || strcmp(str, "inff") == 0)
    d = INFINITY;
  if (strcmp(str, "-inf") == 0 || strcmp(str, "-inff") == 0)
    d = -INFINITY;
  if (strcmp(str, "nan") == 0 || strcmp(str, "nanf") == 0)
    d = NAN;
  return (d);
}

bool ScalarConverter::isCastableToChar(double d, char* end) {
  return (d > std::numeric_limits<char>::min() &&
          d < std::numeric_limits<char>::max() && end[0] == '\0' &&
          std::fmod(d, 1.0) == 0);
}

bool ScalarConverter::isCastableToInt(double d, char* end) {
  return (d > std::numeric_limits<int>::min() &&
          d < std::numeric_limits<int>::max() && end[0] == '\0' &&
          std::fmod(d, 1.0) == 0);
}

bool ScalarConverter::isCastableToFloat(double d, char* end) {
  return (d > -std::numeric_limits<float>::max() &&
          d < std::numeric_limits<float>::max() && end[0] == 'f');
}

void ScalarConverter::convertPrintChar(double d) {
  char c = d;
  display(c);
}

void ScalarConverter::convertPrintInt(double d) {
  int i = d;
  display(i);
}

void ScalarConverter::convertPrintFloat(double d) {
  float f = d;
  display(f);
}

template <typename T>
void ScalarConverter::display(T n) {
  printChar(n);
  printInt(n);
  printFloat(n);
  printDouble(n);
}

template <typename T>
void ScalarConverter::printChar(T n) {
  std::cout << "char:\t";
  if (n < std::numeric_limits<char>::min() ||
      n > std::numeric_limits<char>::max() || isnan(n)) {
    std::cout << "impossible" << std::endl;
    return;
  }
  //   char c = (char)n;
  char c = static_cast<char>(n);
  if (!isprint(c)) {
    std::cout << "non displayable" << std::endl;
    return;
  }
  std::cout << "'" << c << "'" << std::endl;
}

template <typename T>
void ScalarConverter::printInt(T n) {
  std::cout << "int:\t";
  if (n < std::numeric_limits<int>::min() ||
      n > std::numeric_limits<int>::max() || isnan(n)) {
    std::cout << "impossible" << std::endl;
    return;
  }
  //   int i = (int)n;
  int i = static_cast<int>(n);
  std::cout << i << std::endl;
}

template <typename T>
void ScalarConverter::printFloat(T n) {
  std::cout << "float:\t";
  if ((n < -std::numeric_limits<float>::max() ||
       n > std::numeric_limits<float>::max()) &&
      !isinf(n)) {
    std::cout << "impossible" << std::endl;
    return;
  }
  //   float f = (float)n;
  float f = static_cast<float>(n);
  std::cout << std::fixed;
  std::cout << std::setprecision(1);
  std::cout << f << "f" << std::endl;
}

template <typename T>
void ScalarConverter::printDouble(T n) {
  std::cout << "double:\t";
  if ((n < -std::numeric_limits<double>::max() ||
       n > std::numeric_limits<double>::max()) &&
      !isinf(n)) {
    std::cout << "impossible" << std::endl;
    return;
  }
  //   double d = (double)n;
  double d = static_cast<double>(n);
  std::cout << std::fixed;
  std::cout << std::setprecision(1);
  std::cout << d << std::endl;
}
