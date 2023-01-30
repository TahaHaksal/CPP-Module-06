#include <iostream>
#include <cmath>
#include <climits>
#include <stdlib.h>
#include <cstring>

// double my_atof(const char* str)
// {
// 	double sign = 1.0;
// 	double value = 0.0;
// 	double exponent = 1.0;
// 	int exponent_sign = 1;
// 	int exponent_value = 0;
// 	int digit_count = 0;
// 	bool exponent_set = false;

// 	if (str == nullptr) {
// 		return 0.0;
// 	}

// 	if (*str == '-') {
// 		sign = -1.0;
// 		str++;
// 	} else if (*str == '+') {
// 		str++;
// 	}

// 	if (!strncmp (str, "inf", 3))
// 		return (INFINITY * sign);
// 	else if (!strncmp(str, "nan", 3))
// 		return (NAN);
// 	while (*str != '\0') {
// 		if (*str >= '0' && *str <= '9') {
// 			digit_count++;
// 			if (digit_count > 308) {
// 				if (exponent_set) {
// 					exponent_value = (exponent_sign == 1) ? INT_MAX : INT_MIN;
// 				} else {
// 					if (sign == 1.0) {
// 						return INFINITY;
// 					} else {
// 						return -INFINITY;
// 					}
// 				}
// 			}
// 			value = value * 10.0 + (*str - '0');
// 		} else if (*str == '.') {
// 			str++;
// 			break;
// 		} else if ((*str == 'e' || *str == 'E') && !exponent_set) {
// 			exponent_set = true;
// 			str++;
// 			if (*str == '-') {
// 				exponent_sign = -1;
// 				str++;
// 			} else if (*str == '+') {
// 				str++;
// 			}
// 		} else {
// 			break;
// 		}
// 		str++;
// 	}

// 	while (*str != '\0') {
// 		if (*str >= '0' && *str <= '9') {
// 			exponent_value = exponent_value * 10 + (*str - '0');
// 		} else {
// 			break;
// 		}
// 		str++;
// 	}

// 	if (exponent_set) {
// 		exponent = pow(10.0, exponent_value * exponent_sign);
// 		value *= exponent;
// 	}

// 	return sign * value;
// }

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
	if (strlen(av[1]) == 1)
		x = av[1][0] - '0';
	else
		x = strtod(av[1], NULL);
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
		std::cout << x << "f"<< std::endl;
	}
	{
		std::cout << "Double: ";
		std::cout << x << std::endl;
	}
}
