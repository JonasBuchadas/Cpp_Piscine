#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat(std::string const name, int grade) throw(std::exception) : name(name) {
  setGrade(grade);
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
  *this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
  if (&this == src)
    return (*this);
}

int Bureaucrat::getGrade() { return this->grade; }

std::string Bureaucrat::getName() { return this->name; }

void Bureaucrat::setGrade(int grade) throw(std::exception) {
  this->grade = gradeControl(grade);
}

int Bureaucrat::gradeControl(int grade) throw(std::exception) {
  if (grade <= 0)
    throw Bureaucrat::GradeTooHighException();
  if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
  return grade;
}

void Bureaucrat::decrementGrade() throw(std::exception) {
  setGrade(++this->grade);
}

void Bureaucrat::incrementGrade() throw(std::exception) {
  setGrade(--this->grade);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &b) {
  out << b.getName() << " bureaucrat grade " << b.getGrade() << "."
      << std::endl;
  return out;
}
