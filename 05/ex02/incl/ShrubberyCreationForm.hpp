#pragma once
#include <AForm.hpp>

class ShrubberyCreationForm : public AForm
{
private:
	/* data */
public:
	ShrubberyCreationForm(std::string name);
	~ShrubberyCreationForm();
	void execute(Bureaucrat const &executor) const throw(std::exception);
};
