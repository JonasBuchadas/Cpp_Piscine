#pragma once
#ifndef __ARRAY_TPP__
#define __ARRAY_TPP__

#include <Array.hpp>

template <typename T>
Array<T>::Array() : _array( new T[0] ), _size( 0 ) {}

template <typename T>
Array<T>::Array( unsigned int n ) : _array( new T[n] ), _size( n ) {}

template <typename T>
Array<T>::~Array() {
  delete[] _array;
}

template <typename T>
T& Array<T>::operator[]( unsigned int i ) throw( std::exception ) {
  if ( i >= _size )
    throw Array<T>::OutOfBounds();
  return _array[i];
}

template <typename T>
Array<T>::Array( const Array<T>& src )
    : _array( new T[src._size] ), _size( src._size ) {
  for ( unsigned int i = 0; i < _size; i++ )
    _array[i] = src._array[i];
}

template <typename T>
Array<T>& Array<T>::operator=( Array<T>& src ) {
  if ( this == &src )
    return *this;
  _size = src.size();
  delete[] _array;
  _array = new T[src.size()];
  for ( unsigned int i = 0; i < _size; i++ )
    _array[i] = src[i];
  return *this;
}

template <typename T>
unsigned int Array<T>::size() {
  return _size;
}

#endif
