#pragma once
#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include <stdint.h>

struct Data {
  int rnd;
};

class Serializer {
 public:
  static uintptr_t serialize(Data *ptr);
  static Data     *deserialize(uintptr_t raw);
};

#endif
