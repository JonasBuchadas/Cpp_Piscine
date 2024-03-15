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
    addToList( numb );
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
  _list        = src._list;
  _sortedList  = src._sortedList;
  _deque       = src._deque;
  _sortedDeque = src._sortedDeque;
  return ( *this );
}

void PmergeMe::addToList( int value ) {
  if ( std::find( _list.begin(), _list.end(), value ) != _list.end() )
    throw PmergeMe::DuplicateValueException();
  _list.push_back( value );
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
  for ( listIter iter = _list.begin(); iter != _list.end(); ++iter )
    std::cout << *iter << " ";
  std::cout << std::endl;

  _listTime = clock();
  mergeInsertSortList();
  _listTime = clock() - _listTime;

  _dequeTime = clock();
  mergeInsertSortDeque();
  _dequeTime = clock() - _dequeTime;

  _vectorTime = clock();
  mergeInsertSortVector();
  _vectorTime = clock() - _vectorTime;

  std::cout << "After: ";
  for ( listIter iter = _sortedList.begin(); iter != _sortedList.end(); ++iter )
    std::cout << *iter << " ";
  std::cout << std::endl;

  std::cout << "After: ";
  for ( dequeIter iter = _sortedDeque.begin(); iter != _sortedDeque.end(); ++iter )
    std::cout << *iter << " ";
  std::cout << std::endl;

  std::cout << "After: ";
  for ( vectorIter iter = _sortedVector.begin(); iter != _sortedVector.end(); ++iter )
    std::cout << *iter << " ";
  std::cout << std::endl;

  std::cout << "Time to process a range of " << _list.size() << " elements with std::list : ";
  std::cout << (double)( (double)_listTime / CLOCKS_PER_SEC ) * 1000 << " miliseconds " << std::endl;

  std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : ";
  std::cout << (double)( (double)_dequeTime / CLOCKS_PER_SEC ) * 1000 << " miliseconds " << std::endl;

  std::cout << "Time to process a range of " << _deque.size() << " elements with std::vector : ";
  std::cout << (double)( (double)_vectorTime / CLOCKS_PER_SEC ) * 1000 << " miliseconds " << std::endl;
}

void PmergeMe::mergeInsertSortList( void ) {
  listIter iter = _list.begin();

  for ( ; iter != _list.end(); ) {
    int key = *iter;
    ++iter;

    if ( iter != _list.end() ) {
      if ( *iter > key )
        _listPair.push_back( std::make_pair( key, *iter ) );
      else
        _listPair.push_back( std::make_pair( *iter, key ) );
      ++iter;
    }
  }
  // std::cout << "before pair sort" << std::endl;
  // printListPair( _listPair );
  recursiveSortList( _listPair, 0 );
  // std::cout << "after pair sort" << std::endl;
  // printListPair( _listPair );

  insertList();
}

void PmergeMe::insertList( void ) {
  std::list<std::pair<int, int> >::iterator iter = _listPair.begin();

  for ( ; iter != _listPair.end(); ++iter ) {
    _sortedList.push_back( iter->first );
  }

  iter = _listPair.begin();
  for ( ; iter != _listPair.end(); ++iter ) {
    listIter iter2 = _sortedList.begin();
    while ( iter2 != _sortedList.end() && *iter2 < iter->second )
      ++iter2;
    _sortedList.insert( iter2, iter->second );
  }
  if ( _list.size() % 2 != 0 ) {
    int      lastNumber = *( --_list.end() );
    listIter iter       = _sortedList.begin();
    while ( iter != _sortedList.end() && *iter < lastNumber )
      ++iter;
    _sortedList.insert( iter, lastNumber );
  }
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
  // std::cout << "before pair sort" << std::endl;
  // printVectorPair( _vectorPair );
  recursiveSortVector( _vectorPair, 0 );
  // std::cout << "after pair sort" << std::endl;
  // printVectorPair( _vectorPair );
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

void PmergeMe::recursiveSortList( std::list<std::pair<int, int> >& listPairs, size_t size ) {
  if ( size == listPairs.size() )
    return;
  std::list<std::pair<int, int> >::iterator it = _listPair.begin();

  std::list<std::pair<int, int> >::iterator ite = _listPair.begin();
  for ( size_t i = 0; i < size; i++ ) {
    ite++;
  }
  for ( ; it != ite; it++ ) {
    if ( it->first > ite->first ) {
      std::swap( *it, *ite );
    }
  }
  recursiveSortList( listPairs, ++size );
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
