#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat() : name( "" ) {}

Bureaucrat::Bureaucrat( std::string const name, int grade ) throw( std::exception ) : name( name ) {
  setGrade( grade );
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat( const Bureaucrat &src ) {
  *this = src;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &src ) {
  if ( this == &src )
    return ( *this );
  this->grade = src.grade;
  return ( *this );
}

int Bureaucrat::getGrade() { return this->grade; }

int Bureaucrat::getGrade() const { return this->grade; }

std::string Bureaucrat::getName() { return this->name; }

void Bureaucrat::setGrade( int grade ) throw( std::exception ) {
  this->grade = gradeControl( grade );
}

int Bureaucrat::gradeControl( int grade ) throw( std::exception ) {
  if ( grade <= 0 )
    throw Bureaucrat::GradeTooHighException();
  if ( grade > 150 )
    throw Bureaucrat::GradeTooLowException();
  return grade;
}

void Bureaucrat::decrementGrade() throw( std::exception ) {
  setGrade( ++this->grade );
}

void Bureaucrat::incrementGrade() throw( std::exception ) {
  setGrade( --this->grade );
}

void Bureaucrat::signForm( AForm &f ) {
  try {
    f.beSigned( *this );
  } catch ( const std::exception &e ) {
    std::cout << "Bureaucrat " << this->name << " couldn't sign form "
              << f.getName() << " because grade is lower." << std::endl;
    return;
  }
  std::cout << "Bureaucrat " << this->name << " signed form " << f.getName() << std::endl;
}

void Bureaucrat::executeForm( AForm &f ) {
  try {
    f.execute( *this );
    std::cout << this->name << " executed " << f.getName() << std::endl;
  } catch ( const std::exception &e ) {
    std::cerr << "Form " << f.getName() << " couldn't be executed because " << e.what() << std::endl;
  }
}

std::ostream &operator<<( std::ostream &out, Bureaucrat &b ) {
  out << b.getName() << " bureaucrat grade " << b.getGrade() << "." << std::endl;
  return out;
}
