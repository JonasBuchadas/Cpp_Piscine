#pragma once
#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

class PmergeMe {
 private:
  std::deque<int>                   _deque;
  std::deque<int>                   _sortedDeque;
  std::deque<std::pair<int, int> >  _dequePair;
  std::vector<int>                  _vector;
  std::vector<int>                  _sortedVector;
  std::vector<std::pair<int, int> > _vectorPair;
  clock_t                           _dequeTime;
  clock_t                           _vectorTime;

  typedef std::deque<int>::iterator  dequeIter;
  typedef std::vector<int>::iterator vectorIter;

  PmergeMe( void );

  void mergeInsertSortDeque( void );
  void insertDeque( void );

  void mergeInsertSortVector( void );
  void insertVector( void );

  void addToDeque( int value );
  void addToVector( int value );

  void recursiveSortDeque( std::deque<std::pair<int, int> >& dequePairs, size_t size );
  void recursiveSortVector( std::vector<std::pair<int, int> >& vectorPairs, size_t size );

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

void printDequePair( std::deque<std::pair<int, int> >& list );
void printVectorPair( std::vector<std::pair<int, int> >& vec );

#endif
