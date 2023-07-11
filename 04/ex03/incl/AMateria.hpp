#pragma once

#include <iostream>
#include <ICharacter.hpp>

class ICharacter;

class AMateria
{
	private:
		int usages;
		bool equipped;
	protected:
		std::string &type;
	public:
		// AMateria();
		AMateria(std::string& type);
		AMateria(AMateria& src);
		virtual ~AMateria();

		AMateria& operator=(AMateria& src);

		std::string const & getType() const;
		int getUsages();
		bool getEquipped();
		void setEquipped(bool equip);

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
