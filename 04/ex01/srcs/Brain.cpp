#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& b)
{
	*this = b;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain default destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& b)
{
	std::cout << "Brain = overload operator called" << std::endl;
	for (unsigned int i = 0; i < 100; i++)
		this->ideas[i] = b.ideas[i];
	return *this;
}

void Brain::insertIdea(std::string idea)
{
	int i = 0;
	while (this->ideas[i] != "")
		i++;
	this->ideas[i] = idea;
}

void Brain::showIdea(int i) const
{
	if (i < 0 || i >= 100)
		std::cout << "Idea not accesible";
	std::cout << "Idea " << i << " is " << ideas[i] << std::endl;
}
