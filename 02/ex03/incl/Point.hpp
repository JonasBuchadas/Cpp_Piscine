#pragma once
#ifndef __POINT_HPP__
#define __POINT_HPP__

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;
public:
	Point();
	Point(float x, float y);
	Point(const Point &p);
	~Point();

	Point operator=(Point p);

	bool operator==(const Point &p) const;

	const Fixed get_x() const;
	const Fixed get_y() const;
};

#endif
