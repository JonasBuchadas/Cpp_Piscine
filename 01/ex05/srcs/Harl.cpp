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

  for (int i = 0; i < 4; i++)
    if (array[i] == level) (this->*funcs[i])();
  std::cout << std::endl;
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
