#include "PmergeMe.hpp"

#include <algorithm>
#include <ctime>
#include <iterator>

PmergeMe::PmergeMe( void ) {}

PmergeMe::PmergeMe( char** input ) {
  for ( int i = 1; input[i]; i++ ) {
    for ( size_t j = 0; input[i][j]; j++ ) {
      if ( ( !isdigit( input[i][j] ) ) && input[i][j] != '-' )
        throw std::out_of_range( "wrong input values" );
    }
    int numb = atoi( input[i] );
    if ( numb < 0 || numb > 2147483647 )
      throw std::out_of_range( "number negative or overflow" );
    addToDeque( numb );
    addToVector( numb );
  }
}

PmergeMe::PmergeMe( const PmergeMe& copy ) {
  *this = copy;
}

PmergeMe::~PmergeMe( void ) {}

PmergeMe& PmergeMe::operator=( const PmergeMe& src ) {
  if ( this == &src ) {
    return ( *this );
  }
  _vector       = src._vector;
  _sortedVector = src._sortedVector;
  _deque        = src._deque;
  _sortedDeque  = src._sortedDeque;
  return ( *this );
}

void PmergeMe::addToDeque( int value ) {
  if ( std::find( _deque.begin(), _deque.end(), value ) != _deque.end() )
    throw PmergeMe::DuplicateValueException();
  _deque.push_back( value );
}

void PmergeMe::addToVector( int value ) {
  if ( std::find( _vector.begin(), _vector.end(), value ) != _vector.end() )
    throw PmergeMe::DuplicateValueException();
  _vector.push_back( value );
}

void PmergeMe::sort( void ) {
  std::cout << "Before: ";
  for ( vectorIter iter = _vector.begin(); iter != _vector.end(); ++iter )
    std::cout << *iter << " ";
  std::cout << std::endl;

  _dequeTime = clock();
  mergeInsertSortDeque();
  _dequeTime = clock() - _dequeTime;

  _vectorTime = clock();
  mergeInsertSortVector();
  _vectorTime = clock() - _vectorTime;

  std::cout << "After: ";
  for ( vectorIter iter = _sortedVector.begin(); iter != _sortedVector.end(); ++iter )
    std::cout << *iter << " ";
  std::cout << std::endl;

  std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : ";
  std::cout << (double)( (double)_dequeTime / CLOCKS_PER_SEC ) * 1000 << " miliseconds " << std::endl;

  std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : ";
  std::cout << (double)( (double)_vectorTime / CLOCKS_PER_SEC ) * 1000 << " miliseconds " << std::endl;
}

void PmergeMe::mergeInsertSortDeque( void ) {
  dequeIter iter = _deque.begin();
  for ( ; iter != _deque.end(); ) {
    int key = *iter;
    ++iter;

    if ( iter != _deque.end() ) {
      if ( *iter > key )
        _dequePair.push_back( std::make_pair( key, *iter ) );
      else
        _dequePair.push_back( std::make_pair( *iter, key ) );
      ++iter;
    }
  }
  recursiveSortDeque( _dequePair, 0 );
  insertDeque();
}

void PmergeMe::mergeInsertSortVector( void ) {
  vectorIter iter = _vector.begin();
  for ( ; iter != _vector.end(); ) {
    int key = *iter;
    ++iter;

    if ( iter != _vector.end() ) {
      if ( *iter > key )
        _vectorPair.push_back( std::make_pair( key, *iter ) );
      else
        _vectorPair.push_back( std::make_pair( *iter, key ) );
      ++iter;
    }
  }
  recursiveSortVector( _vectorPair, 0 );
  insertVector();
}

void PmergeMe::insertDeque( void ) {
  std::deque<std::pair<int, int> >::iterator iter = _dequePair.begin();

  for ( ; iter != _dequePair.end(); ++iter ) {
    _sortedDeque.push_back( iter->first );
  }

  iter = _dequePair.begin();
  for ( ; iter != _dequePair.end(); ++iter ) {
    dequeIter iter2 = _sortedDeque.begin();
    while ( iter2 != _sortedDeque.end() && *iter2 < iter->second )
      ++iter2;
    _sortedDeque.insert( iter2, iter->second );
  }
  if ( _deque.size() % 2 != 0 ) {
    dequeIter iter = _sortedDeque.begin();
    while ( iter != _sortedDeque.end() && *iter < _deque[_deque.size() - 1] )
      ++iter;
    _sortedDeque.insert( iter, _deque[_deque.size() - 1] );
  }
}

void PmergeMe::insertVector( void ) {
  std::vector<std::pair<int, int> >::iterator iter = _vectorPair.begin();

  for ( ; iter != _vectorPair.end(); ++iter ) {
    _sortedVector.push_back( iter->first );
  }

  iter = _vectorPair.begin();
  for ( ; iter != _vectorPair.end(); ++iter ) {
    vectorIter iter2 = _sortedVector.begin();
    while ( iter2 != _sortedVector.end() && *iter2 < iter->second )
      ++iter2;
    _sortedVector.insert( iter2, iter->second );
  }
  if ( _vector.size() % 2 != 0 ) {
    vectorIter iter = _sortedVector.begin();
    while ( iter != _sortedVector.end() && *iter < _vector[_vector.size() - 1] )
      ++iter;
    _sortedVector.insert( iter, _vector[_vector.size() - 1] );
  }
}

void PmergeMe::recursiveSortDeque( std::deque<std::pair<int, int> >& dequePairs, size_t size ) {
  if ( size == dequePairs.size() )
    return;

  for ( size_t i = 0; i < dequePairs.size() - 1; i++ ) {
    if ( dequePairs[i].first > dequePairs[size].first ) {
      std::swap( dequePairs[i], dequePairs[size] );
    }
  }
  recursiveSortDeque( dequePairs, ++size );
}

void PmergeMe::recursiveSortVector( std::vector<std::pair<int, int> >& vectorPairs, size_t size ) {
  if ( size == vectorPairs.size() )
    return;

  for ( size_t i = 0; i < vectorPairs.size() - 1; i++ ) {
    if ( vectorPairs[i].first > vectorPairs[size].first ) {
      std::swap( vectorPairs[i], vectorPairs[size] );
    }
  }
  recursiveSortVector( vectorPairs, ++size );
}

bool pairOrderFunction( std::pair<int, int> a, std::pair<int, int> b ) {
  return a.first < b.first;
}

void printListPair( std::list<std::pair<int, int> >& vec ) {
  std::list<std::pair<int, int> >::iterator itv = vec.begin();

  for ( ; itv != vec.end(); itv++ ) {
    std::cout << "a: " << itv->first << " b: " << itv->second << " ";
    std::cout << std::endl;
  }
}

void printDequePair( std::deque<std::pair<int, int> >& vec ) {
  std::deque<std::pair<int, int> >::iterator itv = vec.begin();

  for ( ; itv != vec.end(); itv++ ) {
    std::cout << "a: " << itv->first << " b: " << itv->second << " ";
    std::cout << std::endl;
  }
}
void printVectorPair( std::vector<std::pair<int, int> >& vec ) {
  std::vector<std::pair<int, int> >::iterator itv = vec.begin();

  for ( ; itv != vec.end(); itv++ ) {
    std::cout << "a: " << itv->first << " b: " << itv->second << " ";
    std::cout << std::endl;
  }
}
