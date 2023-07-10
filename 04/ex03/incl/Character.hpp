#pragma once

#include <iostream>
#include <ICharacter.hpp>

class Character: public ICharacter
{
private:
	static const int inventory_size = 4;
	std::string name;
	AMateria *inventory[inventory_size];
	void deleteAllEquippedMaterias();
protected:
public:
	Character(std::string name);
	Character(const Character& src);
	virtual ~Character();

	Character& operator=(const Character &src);

	std::string const & getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

