#ifndef __BSP_HPP__
#define __BSP_HPP__

#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

bool  bsp( Point const a, Point const b, Point const c, Point const point );
Fixed area_triangle( Point const a, Point const b, Point const c );

#endif
