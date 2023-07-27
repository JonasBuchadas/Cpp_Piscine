#include <AForm.hpp>

AForm::AForm(const std::string name, const int toSign, const int toExecute) : name(name), gradeToSign(AForm::gradeControl(toSign)), gradeToExecute(AForm::gradeControl(toExecute))
{
	this->sign = false;
}

AForm::~AForm()
{
}

std::string AForm::getName()
{
	return this->name;
}

int AForm::getGradeToSign()
{
	return this->gradeToSign;
}

int AForm::getGradeToExecute()
{
	return this->gradeToExecute;
}

bool AForm::isSigned()
{
	return this->sign;
}

void AForm::beSigned(Bureaucrat &b) throw (std::exception)
{
	if (b.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	this->sign = true;
}

void AForm::checkExecution(Bureaucrat const &b) const throw (std::exception)
{
	if (b.getGrade() > this->gradeToExecute)
		throw AForm::GradeTooLowException();
	if (!this->sign)
		throw AForm::FormNotSigned();
}

int AForm::gradeControl(int grade) throw(std::exception)
{
	if (grade <= 0)
		throw AForm::GradeTooHighException();
	if (grade > 150)
		throw AForm::GradeTooLowException();
	return grade;
}

std::ostream &operator<<(std::ostream &out, AForm &f)
{
	out << f.getName() << " AForm grade to sign " << f.getGradeToSign() << " AForm grade to execute " << f.getGradeToExecute() << "and it is ";
	if (!f.isSigned())
		out << "not ";
	out << "signed." << std::endl;
	return out;
}
