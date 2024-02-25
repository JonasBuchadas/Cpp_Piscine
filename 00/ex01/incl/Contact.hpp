#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <ctype.h>

#include <cstring>
#include <iostream>
#include <string>

class Contact {
 private:
  std::string _first_name;
  std::string _last_name;
  std::string _nickname;
  std::string _phone_number;
  std::string _secret;
  bool        _is_saved;

 public:
  Contact( std::string first_name, std::string last_name, std::string nickname,
           std::string phone_number, std::string secret );
  Contact();
  ~Contact();
  std::string firstName();
  std::string lastName();
  std::string nickname();
  std::string phoneNumber();
  std::string secret();
  bool        isSaved();
  void        print();
};

#endif
