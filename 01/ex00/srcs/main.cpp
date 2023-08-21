#include "Zombie.hpp"

int main(void) {
  printf("Zombie\n");
  Zombie zombie = Zombie("Zombie");
  zombie.announce();
  printf("New Chump\n");
  randowChump("Chump");
  printf("New Zombie\n");
  Zombie *nZombie = newZombie("New");
  nZombie->announce();
  delete nZombie;
}
