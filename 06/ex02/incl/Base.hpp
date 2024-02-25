#pragma once
#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include <ctime>
#include <iostream>

class Base {
 public:
  virtual ~Base();
};

Base* generate();
void  identify( Base* p );
void  identify( Base& p );
Base* makeA();
Base* makeB();
Base* makeC();

#endif
