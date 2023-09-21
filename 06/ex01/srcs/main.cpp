#include "Ex01.hpp"

int main() {
  Data *selam = new Data;
  Data *temp;

  selam->rnd     = 42;
  uintptr_t data = Serializer::serialize(selam);
  temp           = Serializer::deserialize(data);

  std::cout << selam->rnd << std::endl;
  std::cout << data << std::endl;
  std::cout << temp->rnd << std::endl;
  delete selam;
}
