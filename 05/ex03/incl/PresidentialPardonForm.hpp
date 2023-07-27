#pragma once
#include <AForm.hpp>

class PresidentialPardonForm : public AForm
{
private:
	std::string target;
public:
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
	virtual void execute(Bureaucrat const &executor) const throw(std::exception);
};
