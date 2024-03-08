#pragma once
#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <iostream>

template <typename T, typename F>
void iter( T *array, int len, F f ) {
  if ( array == NULL ) {
    return;
  }
  for ( int i = 0; i < len; i++ )
    f( array[i] );
}

template <typename T>
void print1( T &t ) {
  std::cout << t << std::endl;
}

#endif
