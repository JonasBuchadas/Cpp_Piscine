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
  void validateInput( std::string& input ) throw( std::exception );
  void validateDateFormat( std::string str ) throw( std::exception );
  void validateDate( std::string date ) throw( std::exception );
  bool isLeapYear( unsigned int year );
  void validateValue( std::string price ) throw( std::exception );
  void onlyDigits( const char* str ) throw( std::exception );

  class FailFileOpenException : public std::exception {
   public:
    virtual const char* what() const throw() {
      return "could not open file.";
    }
  };

  class IncorrectFirstLineException : public std::exception {
   public:
    virtual const char* what() const throw() {
      return "first line of csv should be \"date | value\".";
    }
  };

  class InvalidInputMonthException : public std::exception {
   public:
    virtual const char* what() const throw() {
      return "invalid input: month must be between 1 to 12.";
    }
  };

  class InvalidInputDayException : public std::exception {
   public:
    virtual const char* what() const throw() {
      return "invalid input: day must be between 1 to 31.";
    }
  };

  class NotPositiveNumberException : public std::exception {
   public:
    virtual const char* what() const throw() {
      return "not a positive number.";
    }
  };

  class TooLargeNumberException : public std::exception {
   public:
    virtual const char* what() const throw() {
      return "too large a number.";
    }
  };
};

#endif
