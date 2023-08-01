#pragma once

#include <iostream>
#include <stdlib.h>
#include <string>
#include <limits>
#include <climits>
#include <cfloat>
#include <AConverter.hpp>

class ScalarConverter
{
private:
	template <typename T>
	static void display(T n);
	template <typename T>
	static void printChar(T n);
	template <typename T>
	static void printInt(T n);
	template <typename T>
	static void printFloat(T n);
	template <typename T>
	static void printDouble(T n);

public:
	static void convert(char *str);
};

template <typename T>
void ScalarConverter::display(T n)
{
	printChar(n);
	printInt(n);
	printFloat(n);
	printDouble(n);
}

template <typename T>
void ScalarConverter::printChar(T n)
{
	std::cout << "char: ";
	if (n < std::numeric_limits<char>::min() || n > std::numeric_limits<char>::max())
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	char c = (char)n;
	if (!isprint(c))
	{
		std::cout << "non displayable" << std::endl;
		return;
	}
	std::cout << "'" << c << "'" << std::endl;
}

template <typename T>
void ScalarConverter::printInt(T n)
{
	std::cout << "int: ";
	if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	int i = (int)n;
	std::cout << i << std::endl;
}

template <typename T>
void ScalarConverter::printFloat(T n)
{
	std::cout << "float: ";
	if (n < -std::numeric_limits<float>::max() || n > std::numeric_limits<float>::max())
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	float f = (float)n;
	std::cout << f << "f" << std::endl;
}

template <typename T>
void ScalarConverter::printDouble(T n)
{
	std::cout << "double: ";
	if (n < -std::numeric_limits<double>::max() || n > std::numeric_limits<double>::max())
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	double d = (double)n;
	std::cout << d << std::endl;
}
