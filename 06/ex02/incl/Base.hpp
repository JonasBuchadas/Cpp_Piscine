#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <ctime>

class Base
{
	public:
		virtual ~Base();
};

Base *generate();
void identify(Base *p);
void identify(Base &p);
Base* makeA();
Base* makeB();
Base* makeC();

