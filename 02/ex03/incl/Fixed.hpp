#pragma once
#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <cmath>
#include <iostream>

class Fixed {
 private:
  int raw_bits;
  static const int frac_bits = 8;

 public:
  Fixed();
  Fixed(const Fixed &f);
  Fixed(const int raw);
  Fixed(const float fp);
  ~Fixed();
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

  const Fixed &operator=(const Fixed &f);
  // const Fixed operator=(const Fixed f);

  bool operator>(const Fixed &) const;
  bool operator<(const Fixed &) const;
  bool operator>=(const Fixed &) const;
  bool operator<=(const Fixed &) const;

  bool operator!=(const Fixed &) const;
  bool operator==(const Fixed &) const;

  Fixed operator-(const Fixed &) const;
  Fixed operator+(const Fixed &) const;
  Fixed operator*(const Fixed &) const;
  Fixed operator/(const Fixed &) const;

  Fixed &operator++(void);
  Fixed &operator--(void);
  Fixed operator++(int);
  Fixed operator--(int);

  static Fixed &min(Fixed &f1, Fixed &f2);
  static const Fixed &min(const Fixed &f1, const Fixed &f2);
  static Fixed &max(Fixed &f1, Fixed &f2);
  static const Fixed &max(const Fixed &f1, const Fixed &f2);
};

std::ostream &operator<<(std::ostream &, const Fixed &);

#endif
