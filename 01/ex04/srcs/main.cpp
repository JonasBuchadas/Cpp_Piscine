#include "sed_is_for_losers.hpp"

int main(int argc, char *argv[])
{
	if (argc == 4)
	{
		if (!argv[2][0] || !argv[3][0])
			std::cout << "Strings can't be empty" << std::endl;
		else
			replace(argv[1], argv[2], argv[3]);
	}
	else
		std::cout << "Wrong amount of arguments" << std::endl;
	return 0;
}

void replace(std::string filename, std::string s1, std::string s2)
{
	std::ofstream	output("output");
	std::ifstream	input(filename.c_str());
	std::string		line;
	size_t			i;
	size_t			pos;

	if (!input.good())
	{
		std::cout << "File is invalid or does not exist" << std::endl;
		return ;
	}
	if (!output.good())
	{
		std::cout << "File is invalid or does not exist" << std::endl;
		input.close();
		return;
	}
	while (getline(input, line))
	{
		i = 0;
		while (true)
		{
			pos = line.find(s1, i);
			if (pos != std::string::npos)
			{
				output << line.substr(i, pos - i) << s2;
				i = pos + s1.length();
			}
			else
				break;
		}
		output << &line[i] << std::endl;
	}
	input.close();
	output.close();
}
