#pragma once
#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <iostream>
#include <cstdio>

class Weapon
{
private:
	std::string _type;
public:
	Weapon(std::string type);
	~Weapon();
	const std::string &getType(void);
	void setType(std::string type);
};

#endif
