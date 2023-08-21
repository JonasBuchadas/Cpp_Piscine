#include "Zombie.hpp"

void randowChump(std::string name) {
  Zombie zombie = Zombie(name);
  zombie.announce();
}
