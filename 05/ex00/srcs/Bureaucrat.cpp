#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat(std::string const name, int grade) throw(std::exception) : name(name)
{
	setGrade(grade);
}

Bureaucrat::~Bureaucrat()
{
}

int Bureaucrat::getGrade()
{
	return this->grade;
}

std::string Bureaucrat::getName()
{
	return this->name;
}

void Bureaucrat::setGrade(int grade) throw(std::exception)
{
	gradeControl(grade);
	this->grade = grade;
}

void Bureaucrat::gradeControl(int grade) throw(std::exception)
{
	if (grade <= 0)
		throw e_gth;
	if (grade > 150)
		throw e_gtl;
}

void Bureaucrat::decrementGrade() throw(std::exception)
{
	setGrade(this->grade++);
}

void Bureaucrat::incrementGrade() throw(std::exception)
{
	setGrade(this->grade--);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &b)
{
	out << b.getName() << " bureaucrat grade " << b.getGrade() << "." << std::endl;
	return out;
}
