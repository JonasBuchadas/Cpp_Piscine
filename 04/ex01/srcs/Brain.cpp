#include "Brain.hpp"

Brain::Brain() { std::cout << "Brain default constructor called" << std::endl; }

Brain::Brain(const Brain& b) {
  *this = b;
  std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain() { std::cout << "Brain default destructor called" << std::endl; }

Brain& Brain::operator=(const Brain& b) {
  std::cout << "Brain = overload operator called" << std::endl;
  if (this == &b)
    return *this;
  for (unsigned int i = 0; i < BRAINSIZE; i++)
    this->ideas[i] = b.ideas[i];
  return *this;
}

void Brain::setIdea(int index, const std::string& idea) {
  if (index >= 0 && index < BRAINSIZE) {
    ideas[index] = idea;
  }
}

std::string Brain::getIdea(int index) {
  if (index >= 0 && index < BRAINSIZE) {
    return ideas[index];
  }
  return "";
}
