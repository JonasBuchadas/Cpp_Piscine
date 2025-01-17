#include <Character.hpp>

Character::Character( std::string name ) : name( name ) {
  for ( int i = 0; i < inventory_size; i++ )
    this->inventory[i] = NULL;
  std::cout << "Character with name: " << this->name
            << " default constructor called" << std::endl;
}

Character::Character( const Character& src ) {
  *this = src;
  std::cout << "Character with name: " << this->name << " copy constructor called" << std::endl;
}

Character::~Character() {
  deleteAllEquippedMaterias();
  std::cout << "Character with name: " << this->name
            << " destructor constructor called" << std::endl;
}

Character& Character::operator=( const Character& src ) {
  std::cout << "Character copy operator overload called" << std::endl;
  if ( this == &src )
    return *this;
  deleteAllEquippedMaterias();
  for ( int i = 0; i < inventory_size; i++ ) {
    if ( src.inventory[i] != NULL )
      this->inventory[i] = src.inventory[i]->clone();
  }
  this->name = src.name;
  return *this;
}

std::string const& Character::getName() const { return this->name; }

void Character::equip( AMateria* m ) {
  if ( m->getEquipped() ) {
    std::cout << "Equipment " << m->getType() << " already equipped."
              << std::endl;
    return;
  }
  for ( int i = 0; i < inventory_size; i++ ) {
    if ( inventory[i] == NULL ) {
      inventory[i] = m;
      m->setEquipped( true );
      std::cout << "Character " << this->name << " equiped " << m->getType()
                << " on slot " << i + 1 << std::endl;
      return;
    }
  }
  std::cout << "Character " << this->name << " has all inventory slots filled."
            << std::endl;
}

void Character::unequip( int i ) {
  if ( i < 0 || i > inventory_size ) {
    std::cout << "Inventory has only " << inventory_size << " slots"
              << std::endl;
    return;
  }
  if ( this->inventory[i] == NULL ) {
    std::cout << "Nothing to unequip in this inventory slot" << std::endl;
    return;
  }
  this->inventory[i]->setEquipped( false );
  this->inventory[i]->drop();
  std::cout << "Removed " << this->inventory[i]->getType() << " from inventory." << std::endl;
  this->inventory[i] = NULL;
}

void Character::use( int i, ICharacter& target ) {
  if ( i < 0 || i > inventory_size ) {
    std::cout << "Inventory has only " << inventory_size << " slots"
              << std::endl;
    return;
  }
  if ( this->inventory[i] == NULL ) {
    std::cout << "Nothing to use in this inventory slot" << std::endl;
    return;
  }
  this->inventory[i]->use( target );
}

void Character::deleteAllEquippedMaterias() {
  for ( int i = 0; i < inventory_size; i++ ) {
    if ( inventory[i] != NULL ) {
      delete inventory[i];
      inventory[i] = NULL;
    }
  }
}
