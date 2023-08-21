#include <PresidentialPardonForm.hpp>

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("Presidential Pardon Form", 25, 5) {
  this->target = target;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
    throw(std::exception) {
  AForm::checkExecution(executor);
  std::cout << this->target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
