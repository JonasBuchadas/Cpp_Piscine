#include "Fixed.hpp"

Fixed::Fixed() : raw_bits(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f) {
  std::cout << "Copy constructor called" << std::endl;
  *this = f;
}

Fixed::Fixed(const int raw) {
  std::cout << "Int constructor called" << std::endl;
  this->raw_bits = (raw << Fixed::frac_bits);
}

Fixed::Fixed(const float fp) {
  std::cout << "Float constructor called" << std::endl;
  this->raw_bits = roundf(fp * (1 << Fixed::frac_bits));
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

const Fixed &Fixed::operator=(const Fixed &f) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this == &f)
    return (*this);
  this->raw_bits = f.raw_bits;
  return (*this);
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->raw_bits;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->raw_bits = raw;
}

float Fixed::toFloat(void) const {
  return ((float)this->raw_bits / (float)(1 << Fixed::frac_bits));
}

int Fixed::toInt(void) const { return (this->raw_bits >> Fixed::frac_bits); }

std::ostream &operator<<(std::ostream &out, const Fixed &f) {
  out << f.toFloat();
  return out;
}
