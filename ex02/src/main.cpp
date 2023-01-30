#include <cstdlib>
#include <iostream>
#include "../headers/Base.hpp"
#include "../headers/A.hpp"
#include "../headers/B.hpp"
#include "../headers/C.hpp"
#include <time.h>
#include <unistd.h>

Base* generate(void)
{
	Base* arr[3] = {new A(), new B(), new C()};
	srand(time(NULL));
	int x = rand() % 3;
	// sleep(1);
	for (int i = 0; i < 3; i++)
		if (i != x)
			delete arr[i];
	return (arr[x]);
}

void	identify(Base* ptr)
{
	if (dynamic_cast<A*>(ptr))
		std::cout << "It is A\n";
	else if (dynamic_cast<B*>(ptr))
		std::cout << "It is B\n";
	else
		std::cout << "It is C\n";
}

void	identify(Base& ptr)
{
	try
	{
		A &ref = dynamic_cast<A&>(ptr);
		std::cout << "It is A\n";
	}
	catch (std::bad_cast){}
	try
	{
		B &ref = dynamic_cast<B&>(ptr);
		std::cout << "It is B\n";
	}
	catch (std::bad_cast &e){}
	try
	{
		C &ref = dynamic_cast<C&>(ptr);
		std::cout << "It is C\n";
	}
	catch (std::bad_cast &e){}
	std::cout << "Unknown type\n";
}

int	main(void)
{
	Base *ptr = generate();
	std::cout << "ptr 1:\n";
	identify(ptr);
	identify(*ptr);

	Base *ptr2 = generate();
	std::cout << "ptr 2:\n";
	identify(ptr2);
	identify(*ptr2);
	delete ptr;
	delete ptr2;
}
