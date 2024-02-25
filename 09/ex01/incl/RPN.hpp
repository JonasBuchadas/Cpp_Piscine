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
 public:
  RPN( void );
  ~RPN( void );
  RPN( const RPN& src );
  RPN& operator=( const RPN& src );

  RPNToken getRPNToken( char c );
  void     performOperation( RPNToken operation );
  void     calculate( std::string& input );

 private:
  std::stack<int> _stack;
};

#endif
