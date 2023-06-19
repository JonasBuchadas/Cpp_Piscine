#include "FragTrap.hpp"

FragTrap::FragTrap() {}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap Constructor called" << std::endl;
	setName(name);
	setHitPoints(defaultHitPoints());
	setAttackDamage(defaultAttackDamage());
	setEnergyPoints(defaultEnergyPoints());
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

int FragTrap::defaultHitPoints(void)
{
	return (100);
}

int FragTrap::defaultAttackDamage(void)
{
	return (30);
}

int FragTrap::defaultEnergyPoints(void)
{
	return (100);
}

void FragTrap::attack(const std::string &target)
{
	if (getEnergyPoints() <= 0 || getHitPoints() <= 0)
		std::cout << "FragTrap is unable to attack" << std::endl;
	else
	{
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "FragTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " point of damage" << std::endl;
	}
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
