#pragma once
#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed {
 private:
  int              raw_bits;
  static const int frac_bits = 8;

 public:
  Fixed();
  Fixed(Fixed &f);
  ~Fixed();
  const Fixed &operator=(const Fixed &f);
  int          getRawBits(void) const;
  void         setRawBits(int const raw);
};

#endif
