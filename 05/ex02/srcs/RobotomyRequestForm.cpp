#include <RobotomyRequestForm.hpp>

RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target) : AForm(name, 72, 45) {
	this->target = target;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const throw(std::exception)
{
	srand(time(NULL));
	bool tf = (rand() % 2) != 0;
	AForm::checkExecution(executor);
	std::cout << "(Drilling noises...) ";
	if (tf)
		std::cout << this->target << " has been lobotomized successfully" << std::endl;
	else
		std::cout << "Lobotomy on " <<this->target << " has failed" << std::endl;

}

