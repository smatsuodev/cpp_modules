#include "utils.hpp"
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
	{
		std::cout << "--- Test identify ---" << std::endl;
		A a;
		B b;
		C c;
		Base base;
		identify(&a);
		identify(&b);
		identify(&c);
		identify(&base);
		identify(a);
		identify(b);
		identify(c);
		identify(base);
		std::cout << "---------------------" << std::endl;
	}
	{
		Base * result = generate();
		identify(result);
		delete result;
	}
}
