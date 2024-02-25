#include "Harl.hpp"

Harl::Harl() {
  funcs[0] = &Harl::debug;
  funcs[1] = &Harl::info;
  funcs[2] = &Harl::warning;
  funcs[3] = &Harl::error;
}

Harl::~Harl() {}

void Harl::complain( std::string level ) {
  std::string array[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
  int         i       = -1;
  for ( int j = 0; j < 4; j++ ) {
    if ( array[j] == level ) {
      i = j;
    }
  }
  if ( i == -1 ) {
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    return;
  }
  switch ( i ) {
    case DEBUG:
      std::cout << "[ " << array[i] << " ]" << std::endl;
      ( this->*funcs[i++] )();
    case INFO:
      std::cout << "[ " << array[i] << " ]" << std::endl;
      ( this->*funcs[i++] )();
    case WARNING:
      std::cout << "[ " << array[i] << " ]" << std::endl;
      ( this->*funcs[i++] )();
    case ERROR:
      std::cout << "[ " << array[i] << " ]" << std::endl;
      ( this->*funcs[i++] )();
  }
  return;
}

void Harl::debug() {
  std::cout << "love having extra bacon for my "
               "7XL-double-cheese-triple-pickle-specialketchup burger.I "
               "really do !"
            << std::endl
            << std::endl;
}

void Harl::info() {
  std::cout << "I cannot believe adding extra bacon costs more money. You "
               "didn't put enough bacon in my burger! If you did, I wouldn't "
               "be asking for more!"
            << std::endl
            << std::endl;
}

void Harl::warning() {
  std::cout << "I think I deserve to have some extra bacon for free. I've been "
               "coming for years whereas you started working here since last "
               "month."
            << std::endl
            << std::endl;
}

void Harl::error() {
  std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl
            << std::endl;
}
