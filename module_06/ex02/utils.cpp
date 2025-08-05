#include "utils.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate()
{
	srand(time(NULL));
	int r = rand();
	if (r % 3 == 0)
		return static_cast<Base *>(new A);
	if (r % 3 == 1)
		return static_cast<Base *>(new B);
	return static_cast<Base *>(new C);
}

void identify(Base *p)
{
	A *a = dynamic_cast<A *>(p);
	if (a != NULL)
	{
		std::cout << a << " -> A" << std::endl;
		return;
	}

	B *b = dynamic_cast<B *>(p);
	if (b != NULL)
	{
		std::cout << b << " -> B" << std::endl;
		return;
	}

	C *c = dynamic_cast<C *>(p);
	if (c != NULL)
	{
		std::cout << c << " -> C" << std::endl;
		return;
	}
	std::cout << p << " -> Base" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &result = dynamic_cast<A &>(p);
		(void)result;
		std::cout << "p -> A" << std::endl;
	}
	catch (std::bad_cast &e)
	{
		try
		{
			B &result = dynamic_cast<B &>(p);
			(void)result;
			std::cout << "p -> B" << std::endl;
		}
		catch (std::bad_cast &e)
		{
			try
			{
				C &result = dynamic_cast<C &>(p);
				(void)result;
				std::cout << "p -> C" << std::endl;
			}
			catch (std::bad_cast &e)
			{
				std::cout << "p -> Base" << std::endl;
			}
		}
	}
}
