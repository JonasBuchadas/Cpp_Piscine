#include "polymorphism.hpp"

int main(void) {
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();  // will output the cat sound!
  j->makeSound();
  meta->makeSound();

  const WrongAnimal *wrongMeta = new WrongAnimal();
  const WrongAnimal *k = new WrongCat();
  std::cout << k->getType() << " " << std::endl;
  k->makeSound();
  wrongMeta->makeSound();
  delete meta;
  delete wrongMeta;
  delete i;
  delete j;
  delete k;
  return 0;
}
