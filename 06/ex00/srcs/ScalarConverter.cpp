#include <ScalarConverter.hpp>

// long double ScalarConverter::n = 0;
// int			ScalarConverter::i = 0;
// char 		ScalarConverter::c = '\0';
// float 		ScalarConverter::f = 0.0f;
// double 		ScalarConverter::d = 0.0;

// template <typename T>
// void ScalarConverter::display(T) {
// 	// printChar();
// 	printInt();
// 	printFloat();
// 	printDouble();
// }

void ScalarConverter::convert(char *str) {
	// int		i;
	// float	f;
	// double	d;
  	char*	end;
	double	n;
//   // ScalarConverter::n = atol(str);
//   // std::string::size_type sz;
	n = strtod(str, &end);
	std::cout << "str:\t" << str << std::endl;
	std::cout << "end:\t" << end << std::endl;
	if (n > std::numeric_limits<char>::min() && n < std::numeric_limits<char>::max() && end[0] == '\0')
	{
		char c = atoi(str);
		display(c);
		return;
	}
	if (n > std::numeric_limits<int>::min() && n < std::numeric_limits<int>::max() && end[0] == '\0')
	{
		int i = atoi(str);
		display(i);
		return;
	}
	if (n > -std::numeric_limits<float>::max() && n < std::numeric_limits<int>::max())
	{
		float f = n;
		display(f);
		return;
	}
  // display();
}
