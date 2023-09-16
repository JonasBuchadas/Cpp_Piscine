#include "Ex02.hpp"

int main(void) {
  try {
    Bureaucrat j("Jonas", 5);
    std::cout << j;
    j.incrementGrade();
    std::cout << j;
    RobotomyRequestForm    f = RobotomyRequestForm("Jon");
    PresidentialPardonForm p("Sara");
    ShrubberyCreationForm  s("tree");
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
