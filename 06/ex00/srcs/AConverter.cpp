#include <AConverter.hpp>

AConverter::AConverter(std::string literal)
{
	this->literal = literal;
}

AConverter::~AConverter(){}

void AConverter::display(){
	printChar();
	printInt();
	printFloat();
	printDouble();
}
