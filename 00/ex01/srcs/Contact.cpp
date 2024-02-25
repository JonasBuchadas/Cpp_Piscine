#include "Contact.hpp"

Contact::Contact( std::string first_name, std::string last_name,
                  std::string nickname, std::string phone_number,
                  std::string secret ) {
  this->_first_name   = first_name;
  this->_last_name    = last_name;
  this->_nickname     = nickname;
  this->_phone_number = phone_number;
  this->_secret       = secret;
}

Contact::Contact() {}

Contact::~Contact() {}

std::string Contact::firstName() { return this->_first_name; }

std::string Contact::lastName() { return this->_last_name; }

std::string Contact::nickname() { return this->_nickname; }

std::string Contact::phoneNumber() { return this->_phone_number; }

std::string Contact::secret() { return this->_secret; }

bool Contact::isSaved() { return this->_is_saved; }

void Contact::print() {
  std::cout << "First Name: " + _first_name << std::endl;
  std::cout << "Last Name: " + _last_name << std::endl;
  std::cout << "Nickname: " + _nickname << std::endl;
  std::cout << "Phone Number: " + _phone_number << std::endl;
  std::cout << "Secret: " + _secret << std::endl;
}
