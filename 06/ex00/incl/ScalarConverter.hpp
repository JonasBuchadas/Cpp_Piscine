#pragma once

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string.h>
#include <limits>


class ScalarConverter
{
	private:
		typedef bool (*funcValPtr)(double d, char* end);
		typedef void (*funcPrintPtr)(double d);

		static double convertMathConsts(double d, char* str);
		static bool isCastableToChar(double d, char* end);
		static bool isCastableToInt(double d, char* end);
		static bool isCastableToFloat(double d, char* end);
		static void convertPrintChar(double d);
		static void convertPrintInt(double d);
		static void convertPrintFloat(double d);

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
