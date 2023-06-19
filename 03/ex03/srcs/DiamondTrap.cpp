#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap Constructor called" << std::endl;
	this->_name = name;
	setHitPoints(defaultHitPoints());
	setAttackDamage(defaultAttackDamage());
	setEnergyPoints(defaultEnergyPoints());
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	if (getEnergyPoints() <= 0 || getHitPoints() <= 0)
		std::cout << "DiamondTrap is unable to speak" << std::endl;
	else
	{
		std::cout << "DiamondTrap name is :\t" << _name << std::endl;
		std::cout << "ClapTrap name is :\t" << getName() << std::endl;
	}
}
