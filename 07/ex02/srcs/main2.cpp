#include <Array.hpp>
#include <iostream>

#define MAX_VAL 750
int main(int, char**) {
  Array<int> numbers(2);
  for (int i = 0; i < 2; i++) numbers[i] = i;

  for (int i = 0; i < 2; i++) std::cout << numbers[i] << std::endl;

  try {
    std::cout << numbers[-1] << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}
