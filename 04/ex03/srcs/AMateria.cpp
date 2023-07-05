#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << this->type << " default constructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter &target)
{

}
