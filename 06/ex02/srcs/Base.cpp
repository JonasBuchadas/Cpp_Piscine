#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base *makeA() { return new A(); }

Base *makeB() { return new B(); }

Base *makeC() { return new C(); }

Base *generate() {
  Base *(*f[])() = {makeA, makeB, makeC};
  srand(time(0));
  return f[rand() % 3]();
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "C" << std::endl;
  else
    std::cout << "Unknown type" << std::endl;
}

void identify(Base &p) {
  try {
    A &a = dynamic_cast<A &>(p);
    (void)a;
    std::cout << "A" << std::endl;
  } catch (std::exception &e) {
    try {
      B &b = dynamic_cast<B &>(p);
      (void)b;
      std::cout << "B" << std::endl;
    } catch (std::exception &e) {
      try {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "C" << std::endl;
      } catch (std::exception &e) {
        std::cout << "Unknown type" << std::endl;
      }
    }
  }
}
