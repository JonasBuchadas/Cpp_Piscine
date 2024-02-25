#include "Ex02.hpp"

int main( void ) {
  Cat*     d = new Cat();
  AAnimal* c = new Cat();
  d->getBrain().setIdea( 0, "smart idea" );
  Cat* d1 = new Cat( *d );
  Cat* d2 = d1;
  std::cout << d->getType() << " got " << d->getBrain().getIdea( 0 ) << std::endl;
  std::cout << d->getType() << " got " << d1->getBrain().getIdea( 0 ) << std::endl;
  std::cout << d->getType() << " got " << d2->getBrain().getIdea( 0 ) << std::endl;
  d1->getBrain().setIdea( 0, "bad idea" );
  std::cout << c->getType() << std::endl;
  std::cout << d->getType() << " got " << d->getBrain().getIdea( 0 ) << std::endl;
  std::cout << d->getType() << " got " << d1->getBrain().getIdea( 0 ) << std::endl;
  std::cout << d->getType() << " got " << d2->getBrain().getIdea( 0 ) << std::endl;
  delete d;
  delete d1;
  delete c;
  /*
          Brain* b1 = new Brain();
          b1->setIdea(0, "smart idea");
          Brain* b2 = new Brain(*b1);
          b1->setIdea(0, "bad idea");
          std::cout << b2->getIdea(0) << std::endl;
          std::cout << b1->getIdea(0) << std::endl;
          delete b1;
          delete b2;

          const AAnimal* animals[SIZE];
          int i = -1;
          while (++i < (SIZE / 2))
                  animals[i] = new Dog();
          i--;
          while (++i < SIZE)
                  animals[i] = new Cat();

          i = -1;
          while (++i < SIZE)
                  delete animals[i];
*/
  return 0;
}
