#pragma once

#include <iostream>
#include <AForm.hpp>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

typedef AForm *(*funcPtr)(std::string target);

class AForm;

class Intern
{
private:
	// const static std::string enumForm[];
public:
	Intern();
	~Intern();
	AForm *makeForm(std::string form, std::string target);
};

// const std::string Intern::enumForm[] = { "a", "b", "c" };
