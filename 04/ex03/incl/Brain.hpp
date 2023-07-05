#pragma once

#include <iostream>
#define BRAINSIZE 100

class Brain
{
private:
	std::string	ideas[BRAINSIZE];
protected:
public:

	Brain();
	Brain(const Brain& b);
	~Brain();
	Brain& operator=(const Brain& b);

	void setIdea(int index, const std::string& idea);
	std::string getIdea(int index);
};

