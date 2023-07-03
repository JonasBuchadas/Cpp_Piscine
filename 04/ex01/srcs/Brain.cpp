#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& b)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = b;
}

Brain::~Brain()
{
	std::cout << "Brain default destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& b)
{
	std::cout << "Brain = overload operator called" << std::endl;
	if (this == &b)
		return *this;
	for (unsigned int i = 0; i < 100; i++)
		this->ideas[i] = b.ideas[i];
	return *this;
}
