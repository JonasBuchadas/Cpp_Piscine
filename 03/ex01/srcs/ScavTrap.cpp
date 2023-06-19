#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap Constructor called" << std::endl;
	setName(name);
	setHitPoints(100);
	setAttackDamage(20);
	setEnergyPoints(50);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
	if (this->getEnergyPoints() <= 0 || this->getHitPoints() <= 0)
		std::cout << "ScavTrap is unable to enter Gate keeper mode" << std::endl;
	else
	{
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
	}
}
