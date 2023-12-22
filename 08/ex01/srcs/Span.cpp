#include <Span.hpp>
#include <algorithm>
#include <exception>
#include <vector>

Span::Span(unsigned int size) : _size(size) {}

Span::~Span() {}

void Span::addNumber(int n) throw(std::exception) {
  if (_array.size() == _size)
    throw Span::MaxSize();
  _array.push_back(n);
}

void Span::addNumbers(std::vector<int> array) throw(std::exception) {
  if (_array.size() + array.size() > _size)
    throw Span::MaxSize();
  _array.insert(_array.end(), array.begin(), array.end());
}

int Span::longestSpan() throw(std::exception) {
  if (_array.size() < 2)
    throw Span::NoSpan();
  int max = *std::max_element(_array.begin(), _array.end());
  int min = *std::min_element(_array.begin(), _array.end());
  return max - min;
}

int Span::shortestSpan() throw(std::exception) {
  if (_array.size() < 2)
    throw Span::NoSpan();
  std::sort(_array.begin(), _array.end());
  int                        shortestSpan = longestSpan();
  std::vector<int>::iterator it;
  for (it = _array.begin(); it != _array.end() - 1; ++it) {
    if ((*(it + 1) - *it) < shortestSpan)
      shortestSpan = *(it + 1) - *it;
    if (shortestSpan == 0)
      return shortestSpan;
  }
  return shortestSpan;
}
