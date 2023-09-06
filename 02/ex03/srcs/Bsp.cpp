#include "Bsp.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Fixed area;
  Fixed area_sum = 0;

  if (point == a || point == b || point == c)
    return (false);
  area     = area_triangle(a, b, c);
  area_sum = area_sum + area_triangle(a, b, point);
  area_sum = area_sum + area_triangle(b, c, point);
  area_sum = area_sum + area_triangle(c, a, point);

  std::cout << "Triangule Area ";
  std::cout << area.toFloat() << std::endl;
  std::cout << "Summed Area ";
  std::cout << area_sum.toFloat() << std::endl;
  return (roundf(area_sum.toFloat()) == roundf(area.toFloat()));
}

Fixed area_triangle(Point const a, Point const b, Point const c) {
  Fixed cross1;
  Fixed cross2;
  Fixed cross3;
  Fixed area;

  cross1 = Fixed(a.get_x() * (b.get_y() - c.get_y()));
  cross2 = Fixed(b.get_x() * (c.get_y() - a.get_y()));
  cross2 = Fixed(c.get_x() * (a.get_y() - b.get_y()));

  area = (cross1 + cross2 + cross3) / Fixed(2.0f);

  if (area >= 0)
    return (area);
  return (area * Fixed(-1.0f));
}
