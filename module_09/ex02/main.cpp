#include <vector>
#include <deque>
#include <iterator>
#include <iostream>
#include <sstream>
#include <sys/time.h>
#include <cstdlib>
#include "PmergeMe.hpp"

static void print_error(const std::string &message) {
	std::cout << message << std::endl;
	exit(1);
}

template <typename Iterator>
static bool isSorted(Iterator first, Iterator last) {
	typename std::iterator_traits<Iterator>::value_type prev = *first;
	for (Iterator it = first; it != last; it++) {
		if (it == first) continue;
		if (prev > *it) return false;

		prev = *it;
	}

	return true;
}

int main(int argc, char **argv) {
	if (argc < 2)
		print_error("too few arguments");
	++argv;
	std::vector<unsigned int> v;
	std::deque<unsigned int> d;
	std::stringstream ss;
	for (int i = 0; i < argc - 1; ++i) {
		char *str = argv[i];
		if (*str == '\0')
			print_error("not a number");
		for (char *p = str; *p != '\0'; ++p) {
			if (*p < '0' || *p > '9')
				print_error("not a number");
		}
		ss << str;
		unsigned int num;
		ss >> num;
		ss.clear();
		v.push_back(num);
		d.push_back(num);
	}

	std::cout << "Before:";
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << ' ' << v[i];
	}
	std::cout << std::endl;

	struct timeval start;
	struct timeval end;
	gettimeofday(&start, NULL);
	std::vector<unsigned int> resultOfVec = pmergeMeVec(v);
	std::cout << "After:";
	for (size_t i = 0; i < resultOfVec.size(); ++i) {
		std::cout << ' ' << resultOfVec[i];
	}
	std::cout << std::endl;
	gettimeofday(&end, NULL);

	if (isSorted(resultOfVec.begin(), resultOfVec.end()))
		std::cout << "Time to process a range of " << v.size() << " elements with std::vector : "
				  << end.tv_sec * 1000000 + end.tv_usec - start.tv_sec * 1000000 - start.tv_usec
				  << " us" << std::endl;
	else
		std::cout << "Failed to sort with std::vector" << std::endl;

	gettimeofday(&start, NULL);
	std::deque<unsigned int> resultOfDeque = pmergeMeDeq(d);
	gettimeofday(&end, NULL);
	if (isSorted(resultOfDeque.begin(), resultOfDeque.end()))
		std::cout << "Time to process a range of " << v.size() << " elements with std::deque  : "
				  << end.tv_sec * 1000000 + end.tv_usec - start.tv_sec * 1000000 - start.tv_usec
				  << " us" << std::endl;
	else
		std::cout << "Failed to sort with std::vector" << std::endl;
}
