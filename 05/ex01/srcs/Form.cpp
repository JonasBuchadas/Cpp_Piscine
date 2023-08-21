#include <Form.hpp>

Form::Form(const std::string name, const int toSign, const int toExecute)
    : name(name),
      gradeToSign(Form::gradeControl(toSign)),
      gradeToExecute(Form::gradeControl(toExecute)) {
  this->sign = false;
}

Form::~Form() {}

std::string Form::getName() { return this->name; }

int Form::getGradeToSign() { return this->gradeToSign; }

int Form::getGradeToExecute() { return this->gradeToExecute; }

bool Form::isSigned() { return this->sign; }

void Form::beSigned(Bureaucrat &b) throw(std::exception) {
  if (b.getGrade() > this->gradeToSign) throw Form::GradeTooLowException();
  this->sign = true;
}

int Form::gradeControl(int grade) throw(std::exception) {
  if (grade <= 0) throw Form::GradeTooHighException();
  if (grade > 150) throw Form::GradeTooLowException();
  return grade;
}

std::ostream &operator<<(std::ostream &out, Form &f) {
  out << f.getName() << " form grade to sign " << f.getGradeToSign()
      << " form grade to execute " << f.getGradeToExecute() << "and it is ";
  if (!f.isSigned()) out << "not ";
  out << "signed." << std::endl;
  return out;
}
