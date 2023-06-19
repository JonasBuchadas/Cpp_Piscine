#include "Bsp.hpp"

int main(void)
{
	const Point a = Point(0.0f, 0.0f);
	const Point b = Point(10.0f, 0.0f);
	const Point c = Point(0.0f, 10.0f);
	const Point p = Point(2.0f, 2.0f);

	if (bsp(a, b, c, p))
		std::cout << "Point is inside triangle" << std::endl;
	else
		std::cout << "Point is not inside triangle" << std::endl;
	return 0;
}
