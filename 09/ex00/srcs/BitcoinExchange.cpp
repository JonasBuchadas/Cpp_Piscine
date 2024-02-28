#include "BitcoinExchange.hpp"

#include <algorithm>
#include <fstream>

BitcoinExchange::BitcoinExchange( void ) : _dataBase( std::map<std::string, double>() ) {}

BitcoinExchange::BitcoinExchange( std::string& filename ) {
  this->addDatabase( filename );
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& src ) {
  *this = src;
}

BitcoinExchange::~BitcoinExchange( void ) {}

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& src ) {
  if ( this == &src ) {
    return ( *this );
  }
  this->_dataBase = src._dataBase;
  return ( *this );
}

void BitcoinExchange::addDatabase( std::string& filename ) {
  std::ifstream file( filename.c_str(), std::ifstream::in );

  if ( !file.is_open() ) {
    std::cout << "Error: could not open file" << std::endl;
    return;
  }

  std::string line;
  std::getline( file, line );
  while ( std::getline( file, line ) ) {
    std::string date  = line.substr( 0, line.find( ',' ) );
    std::string price = line.substr( line.find( ',' ) + 1 );

    _dataBase.insert( std::pair<std::string, double>( date, std::atof( price.c_str() ) ) );
  }
  file.close();
}

void BitcoinExchange::readFile( std::string& filename ) {
  std::ifstream file( filename.c_str(), std::ifstream::in );

  if ( !file.is_open() ) {
    std::cout << "Error: could not open file" << std::endl;
    return;
  }

  std::string line;
  std::getline( file, line );
  while ( std::getline( file, line ) ) {
    try {
      checkInput( line );
      std::string                             date   = line.substr( 0, line.find( '|' ) - 1 );
      double                                  numBtc = std::atof( line.substr( line.find( '|' ) + 1 ).c_str() );
      std::map<std::string, double>::iterator iter   = _dataBase.upper_bound( date );
      if ( iter != _dataBase.begin() )
        --iter;
      std::cout << iter->first << " => " << iter->second << " => " << numBtc * iter->second << std::endl;
    } catch ( std::exception& e ) {
      std::cout << e.what() << std::endl;
    }
  }
  file.close();
}

void BitcoinExchange::checkInput( std::string& input ) {
  std::string check;

  if ( input.find( '|' ) == std::string::npos ) {
    throw std::runtime_error( "Error: bad input => " + input );
  }

  check = input.substr( 0, input.find( '|' ) );
  if ( std::atof( check.substr( 5, 2 ).c_str() ) > 12 ) {
    throw std::runtime_error( "Error: invalid input: month bigger than 12." );
  }

  check = input.substr( 8, 2 );
  if ( std::atof( check.c_str() ) > 31 ) {
    throw std::runtime_error( "Error: invalid input: day bigger than 31." );
  }

  double price = std::atof( input.substr( input.find( '|' ) + 1 ).c_str() );
  if ( price < 0 ) {
    throw std::runtime_error( "Error: not a positive number." );
  }

  if ( price > 1000 ) {
    throw std::runtime_error( "Error: too large a number." );
  }
}
