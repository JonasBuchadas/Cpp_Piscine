#pragma once
#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include <AForm.hpp>
#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

typedef AForm *( *funcPtr )( std::string target );

class AForm;

class Intern {
 private:
 public:
  Intern();
  ~Intern();
  Intern( const Intern &src );

  Intern &operator=( const Intern &src );
  AForm  *makeForm( std::string form, std::string target );
};

#endif
