#include "WrongCat.hpp"

WrongCat::WrongCat() : type("WrongCat")
{
	std::cout << this->type << " default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << this->type << " default destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
