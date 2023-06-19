#pragma once
#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int raw_bits;
		static const int frac_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &f);
		Fixed(const int raw);
		Fixed(const float fp);
		~Fixed();
		const Fixed& operator=(const Fixed& f);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &, const Fixed &);

#endif
