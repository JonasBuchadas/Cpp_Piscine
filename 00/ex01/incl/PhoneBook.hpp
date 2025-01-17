#pragma once
#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include <ctype.h>

#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <sstream>
#include <string>

#include "Contact.hpp"

class Contact;

class PhoneBook {
 private:
  Contact                _contacts[8];
  static short int const _max_size = 8;
  short int              _size;
  short int              _next_index;
  void                   addContact( Contact contact );
  int                    ContactSize();
  void                   IncrementSize();

 public:
  PhoneBook();
  ~PhoneBook();
  void AddContact();
  void Search();
};

#endif
