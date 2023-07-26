#include "Form28b.hpp"

int main(void)
{
	try
	{
		Bureaucrat j("Jonas", 4);
		std::cout << j;
		j.incrementGrade();
		std::cout << j;
		RobotomyRequestForm f("form", "Jonas");
		PresidentialPardonForm p("form", "Sara");
		f.beSigned(j);
		f.execute(j);
		p.beSigned(j);
		p.execute(j);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
