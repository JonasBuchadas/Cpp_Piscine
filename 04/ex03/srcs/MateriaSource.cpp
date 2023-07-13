#include <MateriaSource.hpp>

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < this->materia_size; i++)
		this->inventory[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource default destructor called" << std::endl;
	for (int i = 0; i < this->materia_size; i++)
	{
		if (this->inventory)
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	std::cout << "MateriaSource learnMateria called" << std::endl;
		if (m->getEquipped())
	{
		std::cout << "Materia " << m->getType() << " already equipped." << std::endl;
		return ;
	}
	for (int i = 0; i < this->materia_size; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			m->setEquipped(true);
			std::cout << "Materia Source equiped " << m->getType() << " on slot " << i + 1 << std::endl;
			return ;
		}
	}
	std::cout << "MateriaSource has all materia slots filled." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	std::cout << "MateriaSource createMateria called" << std::endl;
	for (int i = 0; i < this->materia_size; i++)
	{
		if (inventory[i] && inventory[i]->getType() == type)
		{
			std::cout << "MateriaSource will create Materia on index " << i << std::endl;
			return inventory[i]->clone();
		}
	}
	std::cout << "MateriaSource did not found any Materia" << std::endl;
	return NULL;
}
