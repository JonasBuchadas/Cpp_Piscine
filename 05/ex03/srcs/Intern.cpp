#include <Intern.hpp>

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &src) {
  *this = src;
}

Intern &Intern::operator=(const Intern &src) {
  if (this == &src)
    return (*this);
  // No private members to copy
  return *this;
}

AForm *makeShrubberyCreationForm(std::string target) {
  return new ShrubberyCreationForm(target);
}

AForm *makeRobotomyRequestForm(std::string target) {
  return new RobotomyRequestForm(target);
}

AForm *makePresidentialPardonForm(std::string target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target) {
  const std::string enumForm[] = {"shrubbery creation", "robotomy request",
                                  "presidential pardon"};
  const funcPtr     enumFunc[] = {&makeShrubberyCreationForm,
                                  &makeRobotomyRequestForm,
                                  &makePresidentialPardonForm};
  for (int i = 0; i < 3; i++) {
    if (formName == enumForm[i]) {
      AForm *f = (enumFunc[i](target));
      std::cout << "Intern creates " << f->getName() << std::endl;
      return f;
    }
  }
  std::cout << "Intern can't create " << formName << std::endl;
  return NULL;
}
