#include "PhoneBook.hpp"

#include <limits>
#include <string>

static std::string input_request(std::string field);
static void print_header_columns();
static void print_contact_columns(Contact c, int i);
static void print_column(std::string str);
static void pause(std::string str);

PhoneBook::PhoneBook() { this->_size = 0; }

PhoneBook::~PhoneBook() {}

int PhoneBook::ContactSize() { return this->_size; }

void PhoneBook::IncrementSize() { this->_size++; }

void PhoneBook::AddContact() {
  std::string first_name;
  std::string last_name;
  std::string nickname;
  std::string phone_number;
  std::string secret;

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  first_name = input_request("first name");
  if (first_name.empty()) return pause("First name field cannot be empty");
  last_name = input_request("last name");
  if (last_name.empty()) return pause("Last name field cannot be empty");
  nickname = input_request("nickname");
  if (nickname.empty()) return pause("Nickname field cannot be empty");
  phone_number = input_request("phone number");
  if (phone_number.empty()) return pause("Phone number field cannot be empty");
  secret = input_request("darkest secret");
  if (secret.empty()) return pause("Darkest secret field cannot be empty");
  Contact contact(first_name, last_name, nickname, phone_number, secret);
  PhoneBook::addContact(contact);
}

void PhoneBook::addContact(Contact contact) {
  if (_size == _max_size) {
    for (int i = _max_size - 1; i > 0; i--) _contacts[i] = _contacts[i - 1];
    _contacts[0] = contact;
  } else {
    _contacts[_size] = contact;
    _size++;
  }
}

static std::string input_request(std::string field) {
  std::string input;
  std::cout << "Please type the ";
  std::cout << field;
  std::cout << " of the contact" << std::endl;
  std::getline(std::cin, input);
  return (input);
}

void PhoneBook::Search() {
  int i = 0;
  std::string input;
  Contact c;

  if (_size == 0) {
    pause("No contact found");
    return;
  }
  print_header_columns();
  for (int i = 0; i < _size; i++) {
    print_contact_columns(_contacts[i], i + 1);
  }
  std::cout << "Please choose contact number" << std::endl;
  std::cin >> input;
  std::istringstream(input) >> i;
  if (i > _size || i < 1) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    pause("Invalid input");
    return;
  } else {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    _contacts[i - 1].print();
  }
  pause("");
}

static void print_header_columns() {
  print_column("Index");
  print_column("First Name");
  print_column("Last Name");
  print_column("Nickname");
  std::cout << std::endl;
}

static void print_contact_columns(Contact c, int i) {
  std::stringstream ss;
  std::string index;

  ss << i;
  ss >> index;
  print_column(index);
  print_column(c.firstName());
  print_column(c.lastName());
  print_column(c.nickname());
  std::cout << std::endl;
}

static void print_column(std::string str) {
  int len = str.length();
  std::cout << std::setw(10);
  if (len > 10)
    std::cout << str.substr(0, 9) + ".";
  else
    std::cout << str;
  std::cout << "|";
}

static void pause(std::string str) {
  if (!str.empty()) std::cout << str << ". ";
  std::cout << "Press any key to return." << std::endl;
  std::cin.get();
}
