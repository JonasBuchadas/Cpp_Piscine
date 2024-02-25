#pragma once
#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

#include <AForm.hpp>
#include <fstream>

class ShrubberyCreationForm : public AForm {
 private:
  std::string target;

 public:
  ShrubberyCreationForm();
  ShrubberyCreationForm( std::string target );
  ShrubberyCreationForm( const ShrubberyCreationForm &src );
  ~ShrubberyCreationForm();

  ShrubberyCreationForm &operator=( const ShrubberyCreationForm &src );
  void                   execute( Bureaucrat const &executor ) const throw( std::exception );
};

#endif
