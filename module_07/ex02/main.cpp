#include "Array.hpp"
#include <iostream>
#include <cassert>

//__attribute__((destructor))
//static void destructor() {
//	system("leaks -q main");
//}

#define ASSERT_EXCEPT(expr, exception) \
    {                          \
        bool hasThrew = false;                       \
        try { \
            expr; \
        } catch (const exception &e) { \
            hasThrew = true; \
        }                   \
        assert(hasThrew); \
    }

int main() {
	{
		Array<int> array(3);
		array[0] = 1;
		array[1] = 2;
		array[2] = 3;
		assert(array[0] == 1);
		assert(array[1] == 2);
		assert(array[2] == 3);

		Array<int> copyConstructed(array);
		assert(copyConstructed[0] == 1);
		assert(copyConstructed[1] == 2);
		assert(copyConstructed[2] == 3);

		Array<int> assigned;
		assigned = array;
		assert(assigned[0] == 1);
		assert(assigned[1] == 2);
		assert(assigned[2] == 3);
		std::cout << "Array<int> tests passed" << std::endl;
	}

	{
		Array<char> array(3);
		array[0] = 'a';
		array[1] = 'b';
		array[2] = 'c';
		assert(array[0] == 'a');
		assert(array[1] == 'b');
		assert(array[2] == 'c');

		Array<char> copyConstructed(array);
		assert(copyConstructed[0] == 'a');
		assert(copyConstructed[1] == 'b');
		assert(copyConstructed[2] == 'c');

		Array<char> assigned;
		assigned = array;
		assert(assigned[0] == 'a');
		assert(assigned[1] == 'b');
		assert(assigned[2] == 'c');
		std::cout << "Array<char> tests passed" << std::endl;
	}

	{
		Array<std::string> array(3);
		array[0] = "hello";
		array[1] = "world";
		array[2] = "!";
		assert(array[0] == "hello");
		assert(array[1] == "world");
		assert(array[2] == "!");

		Array<std::string> copyConstructed(array);
		assert(copyConstructed[0] == "hello");
		assert(copyConstructed[1] == "world");
		assert(copyConstructed[2] == "!");

		Array<std::string> assigned;
		assigned = array;
		assert(assigned[0] == "hello");
		assert(assigned[1] == "world");
		assert(assigned[2] == "!");
		std::cout << "Array<std::string> tests passed" << std::endl;
	}

	{
		Array<int> array;
		assert(array.size() == 0);

		Array<int> copyConstructed(array);
		assert(copyConstructed.size() == 0);

		Array<int> assigned;
		assigned = array;
		assert(assigned.size() == 0);
		std::cout << "Empty array tests passed" << std::endl;
	}

	{
		Array<int> array(0);
		assert(array.size() == 0);

		Array<int> copyConstructed(array);
		assert(copyConstructed.size() == 0);

		Array<int> assigned;
		assigned = array;
		assert(assigned.size() == 0);
		std::cout << "size = 0 tests passed" << std::endl;
	}

	{
		Array<Array<int> > array(3);
		array[0] = Array<int>(3);
		array[1] = Array<int>(3);
		array[2] = Array<int>(3);
		array[0][0] = 1;
		array[0][1] = 2;
		array[0][2] = 3;
		array[1][0] = 4;
		array[1][1] = 5;
		array[1][2] = 6;
		array[2][0] = 7;
		array[2][1] = 8;
		array[2][2] = 9;
		assert(array[0][0] == 1);
		assert(array[0][1] == 2);
		assert(array[0][2] == 3);
		assert(array[1][0] == 4);
		assert(array[1][1] == 5);
		assert(array[1][2] == 6);
		assert(array[2][0] == 7);
		assert(array[2][1] == 8);
		assert(array[2][2] == 9);

		Array<Array<int> > copyConstructed(array);
		assert(copyConstructed[0][0] == 1);
		assert(copyConstructed[0][1] == 2);
		assert(copyConstructed[0][2] == 3);
		assert(copyConstructed[1][0] == 4);
		assert(copyConstructed[1][1] == 5);
		assert(copyConstructed[1][2] == 6);
		assert(copyConstructed[2][0] == 7);
		assert(copyConstructed[2][1] == 8);
		assert(copyConstructed[2][2] == 9);

		Array<Array<int> > assigned;
		assigned = array;
		assert(assigned[0][0] == 1);
		assert(assigned[0][1] == 2);
		assert(assigned[0][2] == 3);
		assert(assigned[1][0] == 4);
		assert(assigned[1][1] == 5);
		assert(assigned[1][2] == 6);
		assert(assigned[2][0] == 7);
		assert(assigned[2][1] == 8);
		assert(assigned[2][2] == 9);
		std::cout << "Array of Array tests passed" << std::endl;
	}

	{
		Array<int> array(3);
		ASSERT_EXCEPT(array[3], std::exception);

		std::cout<<"Out of bound tests passed"<<std::endl;
	}
}
