#include "Ex03.hpp"

int main(void) {
  try {
    Bureaucrat j("Jonas", 5);
    std::cout << j;
    j.incrementGrade();
    std::cout << j;
    Intern                 i = Intern();
    AForm*                 d = i.makeForm("shrubbery creation", "shrubb");
    RobotomyRequestForm    f("Jonas");
    PresidentialPardonForm p("Sara");
    ShrubberyCreationForm  s("tree");
    if (d) {
      j.executeForm(*d);
    }
    f.beSigned(j);
    p.beSigned(j);
    s.beSigned(j);
    j.executeForm(f);
    j.executeForm(p);
    delete d;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}
