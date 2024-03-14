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
    throw BitcoinExchange::FailFileOpenException();
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
    throw BitcoinExchange::FailFileOpenException();
    return;
  }

  std::string line;
  std::getline( file, line );
  if ( !( line == "date | value" ) ) {
    file.close();
    throw BitcoinExchange::IncorrectFirstLineException();
  }
  while ( std::getline( file, line ) ) {
    try {
      validateInput( line );
      std::string date   = line.substr( 0, line.find( '|' ) - 1 );
      double      numBtc = std::atof( line.substr( line.find( '|' ) + 1 ).c_str() );

      std::map<std::string, double>::iterator iter;
      iter = _dataBase.find( date );
      if ( iter == _dataBase.end() ) {
        iter = _dataBase.lower_bound( date );
        if ( iter != _dataBase.begin() )
          --iter;
      }
      std::cout << date << " => " << numBtc << " = " << numBtc * iter->second << std::endl;
    } catch ( std::exception& e ) {
      std::cout << "Error: " << e.what() << std::endl;
    }
  }
  file.close();
}

void BitcoinExchange::validateInput( std::string& input ) throw( std::exception ) {
  std::string check;
  if ( input.find( '|' ) == std::string::npos ) {
    throw std::runtime_error( "bad input => " + input );
  }

  check = input.substr( 0, input.find( '|' ) );
  validateDate( check );

  std::string price = input.substr( input.find( '|' ) + 1 ).c_str();
  validateValue( price );
}

void BitcoinExchange::validateDateFormat( std::string str ) throw( std::exception ) {
  std::string year  = str.substr( 0, str.find( '-' ) ).c_str();
  std::string month = str.substr( str.find( '-' ) + 1, 2 ).c_str();
  std::string day   = str.substr( str.find_last_of( '-' ) + 1 ).c_str();
  if ( year.size() != 4 || month.size() != 2 || day.size() != 3 )
    throw std::runtime_error( "bad date format => " + str );
  struct tm   time;
  const char* cstr = str.c_str();
  if ( !strptime( cstr, "%Y-%m-%d", &time ) )
    throw std::runtime_error( "bad date format => " + str );
}

void BitcoinExchange::validateDate( std::string date ) throw( std::exception ) {
  validateDateFormat( date );
  int year  = atoi( date.substr( 0, date.find( '-' ) ).c_str() );
  int month = atoi( date.substr( date.find( '-' ) + 1, date.find( '-' ) ).c_str() );
  int day   = atoi( date.substr( date.find_last_of( '-' ) + 1 ).c_str() );
  if ( year < 2009 || year > 2024 )
    throw std::runtime_error( "invalid year input, out of range => " + date );
  if ( month == 2 && day == 29 && isLeapYear( year ) )
    return;
  switch ( month ) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: {
      if ( day <= 31 )
        return;
    } break;
    case 4:
    case 6:
    case 9:
    case 11: {
      if ( day <= 30 )
        return;
    } break;
    case 2: {
      if ( day <= 28 )
        return;
    } break;
  }
  throw std::runtime_error( "invalid date input => " + date );
}

void BitcoinExchange::validateValue( std::string str ) throw( std::exception ) {
  const char* cstr  = str.c_str();
  double      price = atof( cstr );
  if ( price < 0 ) {
    throw BitcoinExchange::NotPositiveNumberException();
  }
  if ( price > 1000 ) {
    throw BitcoinExchange::TooLargeNumberException();
  }
  if ( str.find( '.' ) != str.find_last_of( '.' ) )
    throw std::runtime_error( "invalid value input, multiple decimal separators found => " + str );
  if ( str.find( '.' ) == std::string::npos ) {
    onlyDigits( str.substr( 1 ).c_str() );
  } else {
    onlyDigits( str.substr( 1, str.find( '.' ) - 1 ).c_str() );
    onlyDigits( str.substr( str.find( '.' ) + 1 ).c_str() );
  }
}

bool BitcoinExchange::isLeapYear( unsigned int year ) {
  if ( year % 400 == 0 )
    return 1;
  else if ( year % 100 == 0 )
    return 0;
  else if ( year % 4 == 0 )
    return 1;
  return 0;
}

void BitcoinExchange::onlyDigits( const char* str ) throw( std::exception ) {
  for ( int i = 0; str[i]; i++ ) {
    if ( !std::isdigit( str[i] ) )
      throw std::runtime_error( "invalid value input, invalid characters found => " + (std::string)str );
  }
}
