#include "Ex02.hpp"

int main()
{
	Base *p = generate();
	identify(p);
	identify(*p);
	delete p;
	return (0);
}
