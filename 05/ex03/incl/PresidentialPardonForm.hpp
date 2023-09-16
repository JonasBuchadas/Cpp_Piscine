#pragma once
#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

#include <AForm.hpp>

class PresidentialPardonForm : public AForm {
 private:
  std::string target;

 public:
  PresidentialPardonForm();
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(const PresidentialPardonForm &src);
  ~PresidentialPardonForm();

  PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
  void                    execute(Bureaucrat const &executor) const throw(std::exception);
};

#endif
