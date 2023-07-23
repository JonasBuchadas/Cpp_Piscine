#include "Form28b.hpp"

int main(void)
{
	try
	{
		Bureaucrat j("Jonas", 4);
		std::cout << j;
		j.incrementGrade();
		std::cout << j;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
