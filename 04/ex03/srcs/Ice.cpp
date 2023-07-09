#include <Ice.hpp>

const std::string Ice::_type = "ice";

Ice::Ice() : AMateria(_type)
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice default destructor called" << std::endl;
}

Ice::Ice(const Ice &i) : AMateria("ice")
{
	*this = i;
	std::cout << this->type << " copy constructor called" << std::endl;
}

Ice&   Ice::operator=(const Ice& i) {
    if (this != &i)
		this->operator=(i);
	std::cout << this->type << " equal operator overload called" << std::endl;
    return *this;
}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	AMateria::use(target);
}
