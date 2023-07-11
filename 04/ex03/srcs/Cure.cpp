#include <Cure.hpp>

std::string Cure::_type = "cure";

Cure::Cure() : AMateria(_type)
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure default destructor called" << std::endl;
}

Cure::Cure(const Cure &i) : AMateria(_type)
{
	*this = i;
	std::cout << this->type << " copy constructor called" << std::endl;
}

Cure&   Cure::operator=(const Cure& i) {
    if (this != &i)
		this->AMateria::operator=((AMateria&)i);
	std::cout << this->type << " equal operator overload called" << std::endl;
    return *this;
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	AMateria::use(target);
}
