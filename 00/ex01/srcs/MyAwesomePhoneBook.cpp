#include "MyAwesomePhoneBook.hpp"

static string ShowMenu();

int main(void)
{
	PhoneBook phonebook;
	string option;

	system("clear");
	while (true)
	{
		option = ShowMenu();
		system("clear");
		if (option.compare("ADD") == 0 || option.compare("1") == 0)
		{
			phonebook.AddContact();
			system("clear");
		}
		if (option.compare("SEARCH") == 0 || option.compare("2") == 0)
		{
			phonebook.Search();
			system("clear");
		}
		if (option.compare("EXIT") == 0 || option.compare("3") == 0)
		{
			std::cout << "Thank you for using my Awesome Phonebook" << std::endl;
			system("sleep 2");
			system("clear");
			exit(0);
		}
	}

	return (0);
}

static string ShowMenu()
{
	string option;

	std::cout << "Please type the option of your choice: " << std::endl;
	std::cout << "\"ADD\" or \"1\" | \"SEARCH\" or \"2\" | \"EXIT\" or \"3\"" << std::endl;
	std::cin >> option;

	return option;
}
