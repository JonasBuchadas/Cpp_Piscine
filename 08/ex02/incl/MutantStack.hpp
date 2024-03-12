#pragma once
#ifndef __MUTANT_STACK_HPP
#define __MUTANT_STACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  MutantStack(){};
  ~MutantStack(){};
  MutantStack( const MutantStack& src ) : std::stack<T>( src ){};
  MutantStack& operator=( const MutantStack& src ) {
    if ( this == src ) {
      return ( *this );
    }
    std::stack<T>::operator=( src );
  };

  typedef typename std::stack<T>::container_type::iterator iterator;

  iterator begin( void ) {
    return ( std::stack<T>::c.begin() );
  }

  iterator end( void ) {
    return ( std::stack<T>::c.end() );
  }
};

#endif
