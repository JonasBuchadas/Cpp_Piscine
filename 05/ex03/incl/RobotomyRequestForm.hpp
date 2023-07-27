#pragma once
#include <AForm.hpp>
#include <stdlib.h>
#include <time.h>

class RobotomyRequestForm : public AForm
{
private:
	std::string target;
public:
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	virtual void execute(Bureaucrat const &executor) const throw(std::exception);
};
