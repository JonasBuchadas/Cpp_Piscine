#pragma once
#ifndef __SCAVTRAP_HPP__
# define __SCAVTRAP_HPP__

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:

public:
	ScavTrap(std::string name);
	~ScavTrap();
	void guardGate();
};

#endif
