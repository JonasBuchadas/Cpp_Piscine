#include <RobotomyRequestForm.hpp>

RobotomyRequestForm::RobotomyRequestForm() : AForm( "Robotomy Request Form", 72, 45 ) {}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm( "Robotomy Request Form", 72, 45 ) {
  this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& src ) : AForm( "Robotomy Request Form", 72, 45 ) {
  *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& src ) {
  if ( this == &src )
    return ( *this );
  AForm::operator=( src );
  this->target = src.target;
  return ( *this );
}

void RobotomyRequestForm::execute( Bureaucrat const& executor ) const throw( std::exception ) {
  AForm::checkExecution( executor );
  srand( time( NULL ) );
  bool tf = ( rand() % 2 ) != 0;
  std::cout << "(Drilling noises...) ";
  if ( tf )
    std::cout << this->target << " has been lobotomized successfully" << std::endl;
  else
    std::cout << "Lobotomy on " << this->target << " has failed" << std::endl;
}
