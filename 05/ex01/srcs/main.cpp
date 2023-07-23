#include "Maggots.hpp"

int main(void)
{
	try
	{
		Bureaucrat j("Jonas", 4);
		Form f("Form", 3, 2);
		std::cout << j;
		j.incrementGrade();
		std::cout << j;
		j.signForm(f);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
