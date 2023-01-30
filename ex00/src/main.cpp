#include <iostream>
#include <cmath>
#include <climits>
#include <stdlib.h>
#include <cstring>

void	exit_with_error(std::string error_message)
{
	std::cerr << error_message;
	exit (EXIT_FAILURE);
}
int	main(int ac, char **av)
{
	if (ac != 2)
		exit_with_error("This program needs 1 argument exactly. EX: ./scalar 'argument'");
	double x;
	char *ptr;
	if (strlen(av[1]) == 1)
		x = av[1][0] - '0';
	else
		x = strtod(av[1], &ptr);
	if (*ptr)
		exit_with_error("Takes 1 parameter with no special characters!\n");
	unsigned char c = (unsigned char ) x;
	int	i = (int)x;
	{
		std::cout << "Char: ";
		if (x > 255 || std::isnan(x) || std::isinf(x))
			std::cout << "Impossible " << std::endl;
		else if (c < 32)
			std::cout << "Not displayable" << std::endl;
		else
			std::cout << "'"<< c << "'"<< std::endl;
	}
	{
		std::cout << "Int: ";
		if (x > INT_MAX || x < INT_MIN || std::isnan(x) || std::isinf(x))
			std::cout << "Impossible" << std::endl;
		else
			std::cout << i << std::endl;
	}
	{
		std::cout << "Float: ";
		std::cout << x;
		if (x - floor(x) == 0)
			std::cout << ".0";
		std::cout << "f"<< std::endl;
	}
	{
		std::cout << "Double: ";
		std::cout << x;
		if (x - floor(x) == 0)
			std::cout << ".0";
		std::cout << std::endl;
	}
}
