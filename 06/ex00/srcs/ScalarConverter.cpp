#include <ScalarConverter.hpp>

long long 	ScalarConverter::i = 0;
char 		ScalarConverter::c = 0;
float 		ScalarConverter::f = 0;
double 		ScalarConverter::d = 0;


void ScalarConverter::display()
{
	std::cout << "char: " << ScalarConverter::c << std::endl;
	std::cout << "int: " << ScalarConverter::i << std::endl;
	std::cout << "float: " << ScalarConverter::f << std::endl;
	std::cout << "double: " << ScalarConverter::d << std::endl;
}

void ScalarConverter::convert(char* str)
{
	ScalarConverter::i = atoi(str);
	display();
}

