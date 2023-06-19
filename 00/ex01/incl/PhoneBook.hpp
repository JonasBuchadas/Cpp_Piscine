#ifndef __PHONEBOOK_HPP__
# define __PHONEBOOK_HPP__

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <list>
#include <cstring>
#include <ctype.h>
#include <iomanip>
#include <sstream>
#include <cstdlib>

typedef std::string string;

class Contact;

class PhoneBook
{
private:
	Contact					_contacts[8];
	static short int const	_max_size = 8;
	short int				_size;
	void					addContact(Contact contact);
	int	ContactSize();
	void IncrementSize();
public:
	PhoneBook();
	~PhoneBook();
	void AddContact();
	void Search();
};

#endif
