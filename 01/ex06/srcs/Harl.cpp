#include "Harl.hpp"

Harl::Harl() {
  funcs[0] = &Harl::debug;
  funcs[1] = &Harl::info;
  funcs[2] = &Harl::warning;
  funcs[3] = &Harl::error;
}

Harl::~Harl() {}

void Harl::complain(std::string level) {
  std::string array[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  int         i;
  for (int j = 0; j < 4; j++) {
    if (array[j] == level) {
      i = j;
    }
  }
  switch (i) {
    case 0:
      std::cout << "[ " << array[i] << " ]" << std::endl;
      (this->*funcs[i])();
    case 1:
      std::cout << "[ " << array[i] << " ]" << std::endl;
      (this->*funcs[i])();
    case 2:
      std::cout << "[ " << array[i] << " ]" << std::endl;
      (this->*funcs[i])();
    case 3:
      std::cout << "[ " << array[i] << " ]" << std::endl;
      (this->*funcs[i])();
    default:
      return;
  }
  std::cout << "[ Probably complaining about insignificant problems ]"
            << std::endl;
}

void Harl::debug() {
  std::cout << "love having extra bacon for my "
               "7XL-double-cheese-triple-pickle-specialketchup burger.I "
               "really do !";
}

void Harl::info() {
  std::cout << "I cannot believe adding extra bacon costs more money. You "
               "didn't put enough bacon in my burger! If you did, I wouldn't "
               "be asking for more!";
}

void Harl::warning() {
  std::cout << "I think I deserve to have some extra bacon for free. I've been "
               "coming for years whereas you started working here since last "
               "month.";
}

void Harl::error() {
  std::cout << "This is unacceptable! I want to speak to the manager now.";
}
