#pragma once
#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <iostream>
#include <stack>

enum RPNToken {
  SPACE,
  NUM,
  ADD,
  SUB,
  MULT,
  DIV,
  NONE
};

class RPN {
 private:
  std::stack<int> _stack;

  RPNToken getRPNToken( char c );
  void     performOperation( RPNToken operation ) throw( std::exception );
  void     checkSpace( bool& space ) throw( std::exception );

 public:
  RPN( void );
  ~RPN( void );
  RPN( const RPN& src );
  RPN& operator=( const RPN& src );
  void calculate( std::string& input ) throw( std::exception );

  class DivideByZeroException : public std::exception {
   public:
    virtual const char* what() const throw() {
      return "attempted to divide by zero";
    }
  };

  class NoSpaceBetweenTokensException : public std::exception {
   public:
    virtual const char* what() const throw() {
      return "must have a space between every token";
    }
  };

  class NotEnoughNumbersException : public std::exception {
   public:
    virtual const char* what() const throw() {
      return "not enough numbers to make operation";
    }
  };

  class InvalidTokenException : public std::exception {
   public:
    virtual const char* what() const throw() {
      return "invalid operator/number";
    }
  };

  class InvalidNumberOperationsException : public std::exception {
   public:
    virtual const char* what() const throw() {
      return "invalid number of operations given";
    }
  };
};

#endif
