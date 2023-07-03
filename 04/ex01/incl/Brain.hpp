#pragma once

#include <iostream>

class Brain
{
private:
protected:
public:
	std::string	ideas[100];

	Brain();
	Brain(const Brain& b);
	~Brain();
	Brain& operator=(const Brain& b);

};

