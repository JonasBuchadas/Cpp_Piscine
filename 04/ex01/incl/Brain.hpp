#pragma once

#include <iostream>

class Brain
{
private:
	std::string	ideas[100];
protected:
public:
	Brain();
	Brain(const Brain& b);
	~Brain();
	Brain& operator=(const Brain& a);
	
	void insertIdea(std::string idea);
	void showIdea(int i) const;
};

