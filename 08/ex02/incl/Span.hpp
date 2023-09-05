#pragma once

#include <iostream>
#include <vector>

class Span {
 private:
  unsigned int _size;
  std::vector<int> _array;

 public:
  Span(unsigned int size);
  ~Span();
  void addNumber(int n) throw(std::exception);
  void addNumbers(std::vector<int> array) throw(std::exception);
  int longestSpan() throw(std::exception);
  int shortestSpan() throw(std::exception);

  class MaxSize : public std::exception {
   public:
    virtual const char* what() const throw() { return "size already maxed"; }
  };

  class NoSpan : public std::exception {
   public:
    virtual const char* what() const throw() { return "no span is possible"; }
  };
};

// void Span::addNumber(int n) throw (std::exception) {
//
// }
