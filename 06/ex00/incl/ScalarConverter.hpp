#pragma once
#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <math.h>
#include <string.h>

#include <iomanip>
#include <iostream>
#include <limits>

class ScalarConverter {
 private:
  ScalarConverter();
  ScalarConverter( const ScalarConverter& src );
  ~ScalarConverter();
  ScalarConverter& operator=( const ScalarConverter& src );

  typedef bool ( *funcValPtr )( double d, char* end );
  typedef void ( *funcPrintPtr )( double d, bool b );

  static bool isCastableToChar( double d, char* end );
  static bool isCastableToInt( double d, char* end );
  static bool isCastableToFloat( double d, char* end );
  static void convertPrintChar( double d, bool b );
  static void convertPrintInt( double d, bool b );
  static void convertPrintFloat( double d, bool b );
  static bool isFailedConversion(double d, char *end);

  template <typename T>
  static void display( T n, bool b );
  template <typename T>
  static void printChar( T n, bool b );
  template <typename T>
  static void printInt( T n, bool b );
  template <typename T>
  static void printFloat( T n, bool b );
  template <typename T>
  static void printDouble( T n, bool b );

 public:
  static void convert( char* str );
};

#endif
