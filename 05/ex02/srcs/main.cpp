#include "Form28b.hpp"

int main(void) {
  try {
    Bureaucrat j("Jonas", 5);
    std::cout << j;
    j.incrementGrade();
    std::cout << j;
    RobotomyRequestForm f("Jonas");
    PresidentialPardonForm p("Sara");
    ShrubberyCreationForm s("tree");
    f.beSigned(j);
    p.beSigned(j);
    s.beSigned(j);
    j.executeForm(f);
    j.executeForm(p);
    // j.executeForm(s);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
