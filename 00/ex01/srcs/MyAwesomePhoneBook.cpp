#include "MyAwesomePhoneBook.hpp"

static std::string ShowMenu();

int main(void) {
  PhoneBook phonebook;
  std::string option;

  system("clear");
  while (true) {
    option = ShowMenu();
    system("clear");
    if (option.compare("ADD") == 0) {
      phonebook.AddContact();
      system("clear");
    }
    if (option.compare("SEARCH") == 0) {
      phonebook.Search();
      system("clear");
    }
    if (option.compare("EXIT") == 0) {
      std::cout << "Thank you for using my Awesome Phonebook" << std::endl;
      system("sleep 2");
      system("clear");
      exit(0);
    }
  }

  return (0);
}

static std::string ShowMenu() {
  std::string option;

  std::cout << "Please type the option of your choice: " << std::endl;
  std::cout << "\"ADD\" | \"SEARCH\" | \"EXIT\" " << std::endl;
  std::cin >> option;

  return option;
}
