#pragma once

#include <iostream>
#include <Bureaucrat.hpp>

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool sign;
	const int gradeToSign;
	const int gradeToExecute;
public:
	AForm(const std::string name, const int toSign, const int toExecute);
	virtual ~AForm();

	int getGradeToSign();
	int getGradeToExecute();
	bool isSigned();
	std::string getName();
	void beSigned(Bureaucrat &b) throw(std::exception);
	void checkExecution(Bureaucrat &b) throw(std::exception);
	virtual void execute(Bureaucrat const &executor) throw(std::exception) = 0;

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

	class FormNotSigned : public std::exception {
		public :
			virtual const char * what() const throw()
			{
				return "Form is not signed";
			}
	};
};

std::ostream &operator<<(std::ostream &, AForm&);
