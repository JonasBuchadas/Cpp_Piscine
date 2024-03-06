#include <ScalarConverter.hpp>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter( const ScalarConverter& src ) {
  *this = src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& src ) {
  if ( this == &src )
    return *this;
  return *this;
}

void ScalarConverter::convert( char* str ) {
  char*              end;
  double             d               = strtod( str, &end );
  bool               failedConv      = false;
  const funcValPtr   enumValFunc[]   = { &isCastableToChar, &isCastableToInt, &isCastableToFloat };
  const funcPrintPtr enumPrintFunc[] = { &convertPrintChar, &convertPrintInt, &convertPrintFloat };

  failedConv = isFailedConversion(d, end);
  if ( d == 0 && str[0] != 0 && str[0] != '0' && str[1] == 0 ) {
    d = str[0];
    failedConv = false;
  }
  for ( int i = 0; i < 3; i++ ) {
    if ( enumValFunc[i]( d, end ) ) {
      enumPrintFunc[i]( d, failedConv );
      return;
    }
  }
  display( d, failedConv );
}

bool ScalarConverter::isFailedConversion(double d, char *end) {
  if ( d == 0 && end[0] != 0 && end[0] != '0' )
    return true;
  if ( d == 0 && end[0] != 0 && end[0] == '0' )
    return false;
  if ( end[0] == 0 )
    return false;
  if ( end[0] == 'f' && end[1] == 0 )
    return false;
  return true;
}

bool ScalarConverter::isCastableToChar( double d, char* end ) {
  return ( d > std::numeric_limits<char>::min() &&
           d < std::numeric_limits<char>::max() && end[0] == '\0' &&
           std::fmod( d, 1.0 ) == 0 );
}

bool ScalarConverter::isCastableToInt( double d, char* end ) {
  return ( d > std::numeric_limits<int>::min() &&
           d < std::numeric_limits<int>::max() && end[0] == '\0' &&
           std::fmod( d, 1.0 ) == 0 );
}

bool ScalarConverter::isCastableToFloat( double d, char* end ) {
  return ( d > -std::numeric_limits<float>::max() &&
           d < std::numeric_limits<float>::max() && end[0] == 'f' );
}

void ScalarConverter::convertPrintChar( double d, bool b ) {
  char c = d;
  display( c, b );
}

void ScalarConverter::convertPrintInt( double d, bool b ) {
  int i = d;
  display( i, b );
}

void ScalarConverter::convertPrintFloat( double d, bool b ) {
  float f = d;
  display( f, b );
}

template <typename T>
void ScalarConverter::display( T n, bool b ) {
  printChar( n, b );
  printInt( n, b );
  printFloat( n, b );
  printDouble( n, b );
}

template <typename T>
void ScalarConverter::printChar( T n, bool b ) {
  std::cout << "char:\t";
  if ( ( n < std::numeric_limits<char>::min() ||
         n > std::numeric_limits<char>::max() || isnan( n ) ) ||
       b ) {
    std::cout << "impossible" << std::endl;
    return;
  }
  char c = static_cast<char>( n );
  if ( !isprint( c ) ) {
    std::cout << "non displayable" << std::endl;
    return;
  }
  std::cout << "'" << c << "'" << std::endl;
}

template <typename T>
void ScalarConverter::printInt( T n, bool b ) {
  std::cout << "int:\t";
  if ( ( n < std::numeric_limits<int>::min() ||
         n > std::numeric_limits<int>::max() || isnan( n ) ) ||
       b ) {
    std::cout << "impossible" << std::endl;
    return;
  }
  int i = static_cast<int>( n );
  std::cout << i << std::endl;
}

template <typename T>
void ScalarConverter::printFloat( T n, bool b ) {
  std::cout << "float:\t";
  if ( ( ( n < -std::numeric_limits<float>::max() ||
           n > std::numeric_limits<float>::max() ) &&
         !isinf( n ) ) ||
       b ) {
    std::cout << "impossible" << std::endl;
    return;
  }
  float f = static_cast<float>( n );
  std::cout << std::fixed;
  std::cout << std::setprecision( 1 );
  std::cout << f << "f" << std::endl;
}

template <typename T>
void ScalarConverter::printDouble( T n, bool b ) {
  std::cout << "double:\t";
  if ( ( ( n < -std::numeric_limits<double>::max() ||
           n > std::numeric_limits<double>::max() ) &&
         !isinf( n ) ) ||
       b ) {
    std::cout << "impossible" << std::endl;
    return;
  }
  double d = static_cast<double>( n );
  std::cout << std::fixed;
  std::cout << std::setprecision( 1 );
  std::cout << d << std::endl;
}
