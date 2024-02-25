#pragma once
#ifndef __MUTATED_STACK_HPP
#define __MUTATED_STACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutatedStack : public std::stack<T> {
 private:
  // std::stack<T> _data;

 public:
  MutatedStack(){};
  ~MutatedStack(){};
  MutatedStack( const MutatedStack& src ) : std::stack<T>( src ){};
  MutatedStack& operator=( const MutatedStack& src ) {
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
  // void   push(const T& n);
  // void   pop();
  // T&     top();
  // size_t size();
  // bool   empty() const;
  //   class Iterator {
  //    private:
  //     std::stack<T> tempStack;
  //   }
  //  public:
  //   Iterator(const MutatedStack& stack);

  //   T&        operator*();
  //   Iterator& operator++();
  //   bool      operator!=(const Iterator& other) const;
  // };

  //   Iterator
  //            begin() const;
  //   Iterator end() const;
};

// #include <MutatedStack.tpp>
// #include <MutatedStackIterator.tpp>

#endif
