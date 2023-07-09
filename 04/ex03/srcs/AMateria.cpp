#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << this->type << " default constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Ice default destructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return this->type;
}

// AMateria& AMateria::operator=(const AMateria& src)
// {
// 	return (*this);
// }

void AMateria::use(ICharacter &target)
{
	std::cout << this->type << " has been used on " << target.getName() << std::endl;
}
