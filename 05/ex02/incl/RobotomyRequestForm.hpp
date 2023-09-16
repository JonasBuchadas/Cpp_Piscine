#pragma once
#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

#include <stdlib.h>
#include <time.h>

#include <AForm.hpp>

class RobotomyRequestForm : public AForm {
 private:
  std::string target;

 public:
  RobotomyRequestForm();
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(const RobotomyRequestForm &src);
  ~RobotomyRequestForm();

  RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
  void                 execute(Bureaucrat const &executor) const throw(std::exception);
};

#endif
