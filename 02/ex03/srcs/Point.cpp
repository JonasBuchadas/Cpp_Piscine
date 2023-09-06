#include "Point.hpp"

Point::Point() : x(Fixed()), y(Fixed()) {}

Point::Point(float x, float y) : x(Fixed(x).toFloat()), y(Fixed(y).toFloat()) {}

Point::Point(const Point &p) { *this = p; }

Point::~Point() {}

Point Point::operator=(Point src) {
  if (this == &src)
    return (*this);
  (Fixed) this->x = src.get_x();
  (Fixed) this->y = src.get_y();
  return (*this);
}

bool Point::operator==(const Point &p) const {
  if (this->get_x() != p.get_x() || this->get_y() != p.get_y())
    return (false);
  return (true);
}

const Fixed Point::get_x() const { return this->x; }

const Fixed Point::get_y() const { return this->y; }
