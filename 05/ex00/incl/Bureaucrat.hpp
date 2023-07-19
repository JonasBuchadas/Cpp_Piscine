#include <iostream>

class Bureaucrat
{
private:
	std::string const name;
	int grade;
public:
	Bureaucrat(std::string const name, int grade) throw (std::exception);
	~Bureaucrat();

	std::string getName();
	int getGrade();
	void setGrade(int grade) throw(std::exception);

	void incrementGrade() throw(std::exception);
	void decrementGrade() throw(std::exception);
	void gradeControl(int grade) throw(std::exception);

	class GradeTooHighException : public std::exception{
		public :
			virtual const char * what() const throw()
			{
				return "Bureaucrat Grade is too high";
			}

	} e_gth;

	class GradeTooLowException : public std::exception{
		public :
			virtual const char * what() const throw()
			{
				return "Bureaucrat Grade is too low";
			}
	} e_gtl;
};

std::ostream &operator<<(std::ostream &, Bureaucrat &);
