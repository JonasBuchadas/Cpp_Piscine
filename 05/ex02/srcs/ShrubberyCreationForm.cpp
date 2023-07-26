#include <ShrubberyCreationForm.hpp>

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target) : AForm(name, 145, 137) {
	this->target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const throw(std::exception)
{
	AForm::checkExecution(executor);
}

