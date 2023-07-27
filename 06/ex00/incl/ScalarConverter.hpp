#pragma once

#include <iostream>
#include <stdlib.h>
#include <limits>

class ScalarConverter
{
private:
	static long long	i;
	static char			c;
	static float		f;
	static double		d;
public:
	static void convert(char* str);
	static void display();
};
