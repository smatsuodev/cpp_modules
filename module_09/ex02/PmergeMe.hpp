#ifndef CPP_MODULES_PMERGEME_HPP
#define CPP_MODULES_PMERGEME_HPP

#include <string>
#include <vector>
#include <deque>

template<class T>
T pmergeMe(const T &v) {
	if (v.size() == 1)
		return v;
	if (v.size() == 2) {
		T copy(v);
		if (v[0] > v[1]) {
			copy[0] = v[1];
			copy[1] = v[0];
		}
		return copy;
	}
	T largerNums, smallerNums;
	for (size_t i = 0; i < v.size(); i += 2) {
		if (i + 1 == v.size()) {
			largerNums.push_back(v[i]);
			continue;
		}
		largerNums.push_back(std::max(v[i], v[i + 1]));
		smallerNums.push_back(std::min(v[i], v[i + 1]));
	}
	T sorted = pmergeMe(largerNums);
	for (size_t i = 0; i < smallerNums.size(); ++i) {
		unsigned int num = smallerNums[i];
		sorted.insert(std::lower_bound(sorted.begin(), sorted.end(), num), num);
	}
	return sorted;
}

#endif
