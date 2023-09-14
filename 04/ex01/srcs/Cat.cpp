#include "Cat.hpp"

Cat::Cat() {
  this->type = "Cat";
  std::cout << this->type << " default constructor called" << std::endl;
  this->brain = new Brain();
}

<<<<<<< Updated upstream
Cat::Cat(const Cat &src) : Animal(src) {
  if (src.brain)
    this->brain = new Brain();
  *this = src;
=======
Cat::Cat(const Cat &c) : Animal(c) {


  //   this->type = c.type;
  if (c.brain)
    this->brain = new Brain(*c.brain);
  else
    this->brain = NULL;
>>>>>>> Stashed changes
  std::cout << this->type << " copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src) {
  if (this == &src)
    return *this;
  Animal::operator=(src);
  if (this->brain)
    delete this->brain;
  if (src.brain)
    this->brain = new Brain(*src.brain);
  else
    this->brain = NULL;
  std::cout << this->type << " = operator overload called" << std::endl;
  return *this;
}

Cat::~Cat() {
  std::cout << this->type << " default destructor called" << std::endl;
  delete this->brain;
}

Brain &Cat::getBrain() { return *this->brain; }

void Cat::makeSound() const { std::cout << "Meow" << std::endl; }
