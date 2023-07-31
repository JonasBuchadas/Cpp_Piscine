#pragma once

#include <iostream>
#include <stdlib.h>
#include <string>
#include <limits>
#include <climits>
#include <cfloat>
#include <IConverter.hpp>

class ScalarConverter
{
private:
	static long double	n;
	// static int			i;
	// static char			c;
	// static float		f;
	// static double		d;
	void display();
	void printChar();
	void printInt();
	void printFloat();
	void printDouble();

public:
	static void convert(char* str);
};
