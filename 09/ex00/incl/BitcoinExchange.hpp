#pragma once
#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <iostream>
#include <map>
class BitcoinExchange {
 public:
  // Constructor
  BitcoinExchange( void );
  BitcoinExchange( std::string& filename );
  BitcoinExchange( const BitcoinExchange& copy );

  // Destructor
  ~BitcoinExchange( void );

  // Operator
  BitcoinExchange& operator=( const BitcoinExchange& copy );

  // Methods
  void addData( std::string& filename );
  void readFile( std::string& filename );
  void checkInput( std::string& input );

 private:
  std::map<std::string, double> _data;
};

#endif
