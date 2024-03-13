#pragma once
#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <iostream>
#include <map>
class BitcoinExchange {
 private:
  std::map<std::string, double> _dataBase;
  BitcoinExchange( void );

 public:
  BitcoinExchange( std::string& filename );
  BitcoinExchange( const BitcoinExchange& copy );

  ~BitcoinExchange( void );

  BitcoinExchange& operator=( const BitcoinExchange& copy );

  void addDatabase( std::string& filename );
  void readFile( std::string& filename );
  void checkInput( std::string& input );
};

#endif
