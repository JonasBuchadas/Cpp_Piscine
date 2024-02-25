#include <PresidentialPardonForm.hpp>

PresidentialPardonForm::PresidentialPardonForm() : AForm( "Presidential Pardon Form", 25, 5 ) {}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm( "Presidential Pardon Form", 25, 5 ) {
  this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& src ) : AForm( "Presidential Pardon Form", 25, 5 ) {
  *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& src ) {
  if ( this == &src )
    return ( *this );
  AForm::operator=( src );
  this->target = src.target;
  return ( *this );
}

void PresidentialPardonForm::execute( Bureaucrat const& executor ) const throw( std::exception ) {
  AForm::checkExecution( executor );
  std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
