#pragma once
#ifndef __HARL_H__
#define __HARL_H__

#include <iostream>

#define DEBUG 0
#define INFO 1
#define WARNING 2
#define ERROR 3

class Harl {
  void ( Harl::*funcs[4] )( void );

 public:
  Harl();
  ~Harl();
  void complain( std::string level );

 private:
  void debug( void );
  void info( void );
  void warning( void );
  void error( void );
};

#endif
