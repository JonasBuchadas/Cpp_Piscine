#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>
#include <cstdio>

class Zombie
{
private:
	std::string _name;
public:
	Zombie(std::string name);
	Zombie();
	~Zombie();
	void announce();
	void setName(std::string name);
};

void randowChump(std::string name);
Zombie *newZombie(std::string name);
Zombie *zombieHorde(int N, std::string name);

#endif
