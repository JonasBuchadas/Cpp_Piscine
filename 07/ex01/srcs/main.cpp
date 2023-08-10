#include "Ex01.hpp"

int main(void)
{
	int tab[] = {0, 1, 2, 3};
	std::string tabStr[] = {"Jonas", "Sara", "Ana"};
	iter(tab, 4, print);
	iter(tabStr, 3, print);
	return (0);
}
