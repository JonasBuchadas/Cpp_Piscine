#pragma once

#include <ctype.h>

#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <sstream>
#include <string>

#include "Contact.hpp"

class Contact;

class PhoneBook {
 private:
  Contact _contacts[8];
  static short int const _max_size = 8;
  short int _size;
  void addContact(Contact contact);
  int ContactSize();
  void IncrementSize();

 public:
  PhoneBook();
  ~PhoneBook();
  void AddContact();
  void Search();
};
