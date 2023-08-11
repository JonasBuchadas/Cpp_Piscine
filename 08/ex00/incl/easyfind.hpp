#pragma once

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <deque>

template < typename T >
void easyfind(T &container, int value)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), value);
	if (it != container.end())
		std::cout << "Found at position " << std::distance(container.begin(), it) << std::endl;
	else
		std::cout << "Not found." << std::endl;
}
