#include "Ex01.hpp"

int main(void) {
  Cat* d = new Cat();
  d->getBrain().setIdea(0, "smart idea");
  Cat* d1 = new Cat(*d);
  Cat* d2 = new Cat();
  *d2     = *d1;
  std::cout << d->getType() << " got " << d->getBrain().getIdea(0) << std::endl;
  std::cout << d1->getType() << " got " << d1->getBrain().getIdea(0) << std::endl;
  std::cout << d2->getType() << " got " << d2->getBrain().getIdea(0) << std::endl;

  d2->getBrain().setIdea(0, "bad idea");

  std::cout << d->getType() << " got " << d->getBrain().getIdea(0) << std::endl;
  std::cout << d->getType() << " got " << d1->getBrain().getIdea(0) << std::endl;
  std::cout << d->getType() << " got " << d2->getBrain().getIdea(0) << std::endl;
  delete d;
  delete d1;
  delete d2;

  //   Brain* b1 = new Brain();
  //   b1->setIdea(0, "smart idea");
  //   Brain* b2 = new Brain(*b1);
  //   Brain* b3 = new Brain();
  //   *b3       = *b1;
  //   b1->setIdea(0, "bad idea");
  //   std::cout << b1->getIdea(0) << std::endl;
  //   std::cout << b2->getIdea(0) << std::endl;
  //   std::cout << b3->getIdea(0) << std::endl;
  //   delete b1;
  //   delete b2;
  //   delete b3;

  return 0;
}
