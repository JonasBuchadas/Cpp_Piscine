#include "Fixed.hpp"

Fixed::Fixed() : raw_bits(0) {}

Fixed::Fixed(const Fixed &f)
{
	*this = f;
}

Fixed::Fixed(const int raw)
{
	this->raw_bits = (raw << Fixed::frac_bits);
}

Fixed::Fixed(const float fp)
{
	this->raw_bits = roundf(fp * (1 << Fixed::frac_bits));
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const
{
	return this->raw_bits;
}

void Fixed::setRawBits(int const raw)
{
	this->raw_bits = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->raw_bits / (float)(1 << Fixed::frac_bits));
}

int Fixed::toInt(void) const
{
	return (this->raw_bits >> Fixed::frac_bits);
}

const Fixed& Fixed::operator=(const Fixed& f)
{
	this->raw_bits = f.raw_bits;
	return (*this);
}

// const Fixed Fixed::operator=(const Fixed f)
// {
// 	this->raw_bits = f.raw_bits;
// 	return (*this);
// }

bool Fixed::operator>(const Fixed &f) const
{
	return (this->raw_bits > f.getRawBits());
}

bool Fixed::operator<(const Fixed &f) const
{
	return (this->raw_bits < f.getRawBits());
}

bool Fixed::operator>=(const Fixed &f) const
{
	return (this->raw_bits >= f.getRawBits());
}

bool Fixed::operator<=(const Fixed &f) const
{
	return (this->raw_bits >= f.getRawBits());
}

bool Fixed::operator==(const Fixed &f) const
{
	return (this->raw_bits == f.getRawBits());
}

bool Fixed::operator!=(const Fixed &f) const
{
	return (this->raw_bits != f.getRawBits());
}

Fixed Fixed::operator+(const Fixed &f) const
{
	return (this->raw_bits + f.getRawBits());
}

Fixed Fixed::operator-(const Fixed &f) const
{
	return (this->raw_bits - f.getRawBits());
}

Fixed Fixed::operator*(const Fixed &f) const
{
	return (this->toFloat() * f.toFloat());
}

Fixed Fixed::operator/(const Fixed &f) const
{
	return (this->toFloat() / f.toFloat());
}

Fixed& Fixed::operator++()
{
	++raw_bits;
	return (*this);
}

Fixed &Fixed::operator--()
{
	--raw_bits;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++raw_bits;
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--raw_bits;
	return (temp);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return out;
}
