#ifndef __CONTACT_HPP__
#define __CONTACT_HPP__

#include <ctype.h>

#include <cstring>
#include <iostream>
#include <string>

typedef std::string string;

class Contact {
 private:
  string _first_name;
  string _last_name;
  string _nickname;
  string _phone_number;
  string _secret;
  bool _is_saved;

 public:
  Contact(string first_name, string last_name, string nickname,
          string phone_number, string secret);
  Contact();
  ~Contact();
  string firstName();
  string lastName();
  string nickname();
  string phoneNumber();
  string secret();
  bool isSaved();
  void print();
};

#endif
