#pragma once

#include <iostream>
#include <ICharacter.hpp>

class ICharacter;

class AMateria
{
	protected:
		std::string const &type;
		bool equipped;
	public:
		// AMateria();
		AMateria(std::string const & type);
		// AMateria(const AMateria& src);
		virtual ~AMateria();

		std::string const & getType() const;
		bool getEquipped();
		void setEquipped(bool equip);

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};