#pragma once
#ifndef __WHATEVER_TPP__
#define __WHATEVER_TPP__

#include <iostream>

template <typename T>
void swap( T &a, T &b ) {
  T swap = a;
  a      = b;
  b      = swap;
}

template <typename T>
T max( T a, T b ) {
  if ( a > b )
    return a;
  return b;
}

template <typename T>
T min( T a, T b ) {
  if ( a > b )
    return b;
  return a;
}

#endif
