#include "easyfind.hpp"
#include <cassert>
#include <vector>

int main() {
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	assert(easyfind(v, 3) - v.begin() == 2);
	assert(easyfind(v, 6) - v.begin() == 5);
	return 0;
}
