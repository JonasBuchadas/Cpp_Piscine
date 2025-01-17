#include <ShrubberyCreationForm.hpp>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm( "Shrubbery Creation Form", 145, 137 ) {}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm( "Shrubbery Creation Form", 145, 137 ) {
  this->target = target;
}

ShrubberyCreationForm ::ShrubberyCreationForm( const ShrubberyCreationForm& src ) : AForm( "Shrubbery Creation Form", 145, 137 ) {
  *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& src ) {
  if ( this == &src )
    return ( *this );
  AForm::operator=( src );
  this->target = src.target;
  return ( *this );
}

void ShrubberyCreationForm::execute( Bureaucrat const& executor ) const
    throw( std::exception ) {
  AForm::checkExecution( executor );
  std::ofstream file( ( this->target + "_shrubbery" ).c_str() );
  file << "                      ___" << std::endl;
  file << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
  file << "             ,-'          __,,-- \\" << std::endl;
  file << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
  file << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
  file << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
  file << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
  file << "     (     ,-'                  `." << std::endl;
  file << "      `._,'     _   _             ;" << std::endl;
  file << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
  file << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
  file << "        `--\'   \"Hb  HH  dF\"" << std::endl;
  file << "                \"Hb HH dF" << std::endl;
  file << "                 \"HbHHdF" << std::endl;
  file << "                  |HHHF" << std::endl;
  file << "                  |HHH|" << std::endl;
  file << "                  |HHH|" << std::endl;
  file << "                  |HHH|" << std::endl;
  file << "                  |HHH|" << std::endl;
  file << "                  dHHHb" << std::endl;
  file << "                .dFd|bHb.               o" << std::endl;
  file << "      o       .dHFdH|HbTHb.          o /" << std::endl;
  file << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
  file << "##########################################" << std::endl;
  file.close();
}
