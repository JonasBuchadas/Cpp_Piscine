#include <Ice.hpp>

Ice::Ice() : AMateria("ice")
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
        this->type = i.type;
    return *this;
}

AMateria *Ice::clone()
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
