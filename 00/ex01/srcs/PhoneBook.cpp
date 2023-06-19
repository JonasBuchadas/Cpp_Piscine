#include "PhoneBook.hpp"

static string input_request(string field);
static void print_header_columns();
static void print_contact_columns(Contact c, int i);
static void print_column(string str);
static void pause(string str);

PhoneBook::PhoneBook()
{
	this->_size = 0;
}

PhoneBook::~PhoneBook(){}

int PhoneBook::ContactSize(){return this->_size;}

void PhoneBook::IncrementSize() {this->_size++;}

void PhoneBook::AddContact()
{
	string	first_name;
	string	last_name;
	string	nickname;
	string	phone_number;
	string	secret;

	first_name = input_request("first name");
	last_name = input_request("last name");
	nickname = input_request("nickname");
	phone_number = input_request("phone number");
	secret = input_request("darkest secret");

	if (!first_name.empty() && !last_name.empty() && !nickname.empty() && !phone_number.empty() && !secret.empty()) {
		Contact contact(first_name, last_name, nickname, phone_number, secret);
		PhoneBook::addContact(contact);
	}
}

void PhoneBook::addContact(Contact contact)
{
	if (_size == _max_size) {
		for (int i = _max_size - 1; i > 0; i--)
			_contacts[i] = _contacts[i - 1];
		_contacts[0] = contact;
	} else {
		_contacts[_size] = contact;
		_size++;
	}
}

static string input_request(string field)
{
	char input[100];

	std::cout << "Please type the ";
	std::cout << field;
	std::cout << " of the contact" << std::endl;
	std::cin >> input;

	return (input);
}

void PhoneBook::Search()
{
	int i = 0;
	string input;
	Contact c;

	if (_size == 0)
	{
		pause("No contact found. Press any key to return");
		return;
	}
	print_header_columns();
	while ( i < _size)
	{
		c = _contacts[i];
		print_contact_columns(c, i + 1);
		i++;
	}
	std::cin >> input;
	std::istringstream(input) >> i;
	if (i > _size || i < 1)
		std::cout << "Invalid input" << std::endl;
	else
		_contacts[i - 1].print();
	pause("Press any key to return");
}

static void print_header_columns()
{
	print_column("Index");
	print_column("First Name");
	print_column("Last Name");
	print_column("Nickname");
	std::cout << std::endl;
}

static void print_contact_columns(Contact c, int i) {
	std::stringstream ss;
	string index;

	ss << i;
	ss >> index;
	print_column(index);
	print_column(c.firstName());
	print_column(c.lastName());
	print_column(c.nickname());
	std::cout << std::endl;
}

static void print_column(string str)
{
	int len = str.length();
	std::cout << std::setw(10);
	if (len > 10)
		std::cout << str.substr(0, 9) + ".";
	else
		std::cout << str;
	std::cout << "|";
}

static void pause(string str)
{
	std::cin.ignore();
	std::cout << str << std::endl;
	std::cin.get();
}
