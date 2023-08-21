#include "HumanB.hpp"

#include "Weapon.hpp"

HumanB::~HumanB() {}

HumanB::HumanB(std::string name) { _name = name; }

void HumanB::setWeapon(Weapon &weapon) { this->_weapon = &weapon; }

void HumanB::attack() {
  std::cout << _name << " attacks with their " << _weapon->getType()
            << std::endl;
}
