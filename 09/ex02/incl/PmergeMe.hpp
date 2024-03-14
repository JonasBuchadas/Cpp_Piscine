#pragma once
#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>

class PmergeMe {
 private:
  std::list<int>                  _list;
  std::list<int>                  _sortedList;
  std::list<std::pair<int, int> > _listPair;
  std::deque<int>                 _deque;
  std::deque<int>                 _sortedDeque;
  clock_t                         _listTime;
  clock_t                         _dequeTime;

  typedef std::list<int>::iterator  listIter;
  typedef std::deque<int>::iterator dequeIter;
  PmergeMe( void );

  void mergeInsertSortList( void );
  void insertList( void );

  void mergeInsertSortDeque( void );
  void insertDeque( void );

  void addToList( int value );
  void addToDeque( int value );

 public:
  PmergeMe( char** input );
  ~PmergeMe( void );

  PmergeMe( const PmergeMe& copy );
  PmergeMe& operator=( const PmergeMe& copy );

  void sort( void );

  class DuplicateValueException : public std::exception {
   public:
    virtual const char* what() const throw() {
      return "given duplicate value";
    }
  };
};

template <typename T>
void print( T& num ) {
  std::cout << num << " ";
}

int isSorted( char** av );

#endif
