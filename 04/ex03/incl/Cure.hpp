#pragma once

#include <iostream>
#include <AMateria.hpp>
#include <ICharacter.hpp>

class Cure : public AMateria
{
	private:
		static const std::string _type;
	public:
		Cure();
		Cure(const Cure &i);
		~Cure();

		Cure& operator=(const Cure& i);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};
