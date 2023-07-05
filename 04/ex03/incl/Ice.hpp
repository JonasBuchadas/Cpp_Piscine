#pragma once

#include <iostream>
#include <AMateria.hpp>
#include <ICharacter.hpp>

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &i);
		~Ice();

		Ice& operator=(const Ice& i);

		virtual AMateria* clone();
		virtual void use(ICharacter& target);
};
