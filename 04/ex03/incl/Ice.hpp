#pragma once

#include <iostream>
#include <AMateria.hpp>
#include <ICharacter.hpp>

class Ice : public AMateria
{
	private:
		static const std::string _type;
	public:
		Ice();
		Ice(const Ice &i);
		~Ice();

		Ice& operator=(const Ice& i);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

// const std::string Ice::_type = "ice";
