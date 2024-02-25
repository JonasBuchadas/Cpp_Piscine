#include "Zombie.hpp"

Zombie::Zombie( std::string name ) { this->_name = name; }

Zombie::Zombie() {}

Zombie::~Zombie() {
  std::cout << "Zombie " << _name << " has died." << std::endl;
}

void Zombie::setName( std::string name ) { _name = name; }

void Zombie::announce() {
  std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
