#pragma once

#include <AForm.hpp>
#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

typedef AForm *(*funcPtr)(std::string target);

class AForm;

class Intern {
 private:
  // const static std::string enumForm[];
 public:
  Intern();
  ~Intern();
  AForm *makeForm(std::string form, std::string target);
};

// const std::string Intern::enumForm[] = { "a", "b", "c" };
