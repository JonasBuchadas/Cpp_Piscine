#pragma once

#include <iostream>
#include <Bureaucrat.hpp>

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool sign;
	const int gradeToSign;
	const int gradeToExecute;
public:
	Form(const std::string name, const int toSign, const int toExecute);
	~Form();

	int getGradeToSign();
	int getGradeToExecute();
	bool isSigned();
	std::string getName();
	void beSigned(Bureaucrat &b) throw(std::exception);

	static int gradeControl(int grade) throw(std::exception);

	class GradeTooHighException : public std::exception{
		public :
			virtual const char * what() const throw()
			{
				return "Form Grade is too high";
			}
	};

	class GradeTooLowException : public std::exception{
		public :
			virtual const char * what() const throw()
			{
				return "Form Grade is too low";
			}
	};
};

std::ostream &operator<<(std::ostream &, Form&);
