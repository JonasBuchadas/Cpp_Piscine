#pragma once
#include <iostream>

class AConverter{
	private:
		std::string literal;
	public:
		AConverter(std::string literal);
		~AConverter();
		virtual void printChar() = 0;
		virtual void printInt() = 0;
		virtual void printFloat() = 0;
		virtual void printDouble() = 0;
		virtual void display();
};
