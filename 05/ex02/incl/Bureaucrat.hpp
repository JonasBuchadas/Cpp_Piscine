#pragma once
#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <AForm.hpp>
#include <iostream>

class AForm;

class Bureaucrat {
 private:
  std::string const name;
  int               grade;

 public:
  Bureaucrat();
  Bureaucrat(std::string const name, int grade) throw(std::exception);
  Bureaucrat(const Bureaucrat &src);
  ~Bureaucrat();

  Bureaucrat &operator=(const Bureaucrat &src);
  std::string getName();
  int         getGrade();
  int         getGrade() const;
  void        setGrade(int grade) throw(std::exception);
  void        incrementGrade() throw(std::exception);
  void        decrementGrade() throw(std::exception);
  void        signForm(AForm &f);
  void        executeForm(AForm const &form);
  static int  gradeControl(int grade) throw(std::exception);

  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw() {
      return "Bureaucrat Grade is too high";
    }
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw() {
      return "Bureaucrat Grade is too low";
    }
  };
};

std::ostream &operator<<(std::ostream &, Bureaucrat &);

#endif
