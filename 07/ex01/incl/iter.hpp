#pragma once
#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <iostream>

template <typename T>
void iter(T *array, int len, void (*f)(T const &)) {
  for (int i = 0; i < len; i++)
    f(array[i]);
}

template <typename T>
void print(T &t) {
  std::cout << t << std::endl;
}

#endif
