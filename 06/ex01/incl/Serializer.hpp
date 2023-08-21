#pragma once

#include <stdint.h>

struct Data {
  int rnd;
};

class Serializer {
 public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};
