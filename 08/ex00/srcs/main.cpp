#include "easyfind.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return EXIT_FAILURE;

	int arr[] = {12, 21, 3, 42, 5, 666, 77, 81, 90, 10};

	std::vector<int> vect(arr, arr + sizeof(arr) / sizeof(int));
	std::list<int> list(arr, arr + sizeof(arr) / sizeof(int));
	std::deque<int> deque(arr, arr + sizeof(arr) / sizeof(int));

	easyfind(vect, std::atoi(av[1]));
	easyfind(list, std::atoi(av[1]));
	easyfind(deque, std::atoi(av[1]));

	return EXIT_SUCCESS;
}
