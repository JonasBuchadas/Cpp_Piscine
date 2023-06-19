#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap Constructor called" << std::endl;
	setName(name);
	setHitPoints(100);
	setAttackDamage(30);
	setEnergyPoints(100);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	if (this->getEnergyPoints() <= 0 || this->getHitPoints() <= 0)
		std::cout << "FragTrap is unable to high five guys" << std::endl;
	else
	{
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		std::cout << "FragTrap is now in high five mode" << std::endl;
	}
}
