#pragma once
#ifndef __DIAMONDTRAP_HPP__
# define ___DIAMONDTRAP_HPP__

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string _name;
public:
	DiamondTrap(std::string name);
	~DiamondTrap();
	void whoAmI();
	using ScavTrap::attack;
	using FragTrap::defaultHitPoints;
	using ScavTrap::defaultEnergyPoints;
	using FragTrap::defaultAttackDamage;
};

#endif
