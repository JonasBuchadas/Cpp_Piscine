#include "Mommy.hpp"

int main (void)
{
	Bureaucrat *s = new Bureaucrat("Sara", 1);
	std::cout << *s;
	try
	{
		Bureaucrat *j = new Bureaucrat("Jonas", 0);
		j->incrementGrade();
		s->incrementGrade();
		delete j;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	delete s;
}
