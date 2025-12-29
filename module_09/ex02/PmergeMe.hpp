#ifndef CPP_MODULES_PMERGEME_HPP
#define CPP_MODULES_PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

size_t jacob(size_t n);

template <class T>
std::vector<std::vector<T> >* divideVec(std::vector<std::vector<T> > &pairsSet, int depth) {
	std::vector<std::vector<T> >* newSet = new std::vector<std::vector<T> >;

	newSet->resize(std::pow(2, (depth + 1)));

	for (size_t i = 0; i + 1 < pairsSet[0].size(); i += 2) {
		if (pairsSet[0][i] < pairsSet[0][i + 1]) {
			for (size_t j = 0; j < pairsSet.size(); j++) {
				(*newSet)[j * 2].push_back(pairsSet[j][i + 1]);
				(*newSet)[j * 2 + 1].push_back(pairsSet[j][i]);
			}
		} else {
			for (size_t j = 0; j < pairsSet.size(); j++) {
				(*newSet)[j * 2].push_back(pairsSet[j][i]);
				(*newSet)[j * 2 + 1].push_back(pairsSet[j][i + 1]);
			}
		}
	}

	size_t remainder = (pairsSet[0].size() / 2) * 2;
	for (size_t i = 0; i < pairsSet.size(); i++) {
		for (unsigned int j = remainder; j < pairsSet[i].size(); j++) {
			(*newSet)[i * 2 + 1].push_back(pairsSet[i][j]);
		}
	}
	delete &pairsSet;

	if ((*newSet)[0].size() < 3) {
		if ((*newSet)[0].size() == 2 && (*newSet)[0][0] > (*newSet)[0][1]) {
			T tmp;
			for (size_t i = 0; i < newSet->size(); i++) {
				tmp = (*newSet)[i][0];
				(*newSet)[i][0] = (*newSet)[i][1];
				(*newSet)[i][1] = tmp;
			}
		}

		return (newSet);
	}

	return divideVec(*newSet, depth + 1);
}

template <class T>
size_t insertVec(std::vector<T> &v, size_t upperBound, T value) {
	ssize_t l = -1;
	ssize_t r = upperBound;

	while (l + 1 < r) {
		ssize_t m = (l + r) / 2;

		if (v[m] >= value) {
			r = m;
		} else {
			l = m;
		}
	}

	v.insert(v.begin() + r, value);
	return r;
}

template <class T>
std::vector<std::vector<T> >* mergeVec(std::vector<std::vector<T> > &pairsSet) {
	std::vector<std::vector<T> >* newSet = new std::vector<std::vector<T> >;
		size_t insertedCnt = 1;

	for (size_t i = 0; i + 1 < pairsSet.size(); i += 2) {
		pairsSet[i].insert(pairsSet[i].begin(), pairsSet[i + 1][0]);
	}

	std::vector<size_t> jacobs;
	for (size_t i = 1; ; i++) {
		size_t j = jacob(i);
		if (j < pairsSet[1].size()) {
			jacobs.push_back(j - 1);
		} else {
			jacobs.push_back(pairsSet[1].size() - 1);
			break;
		}
	}

	for (size_t i = 1; i < jacobs.size(); i++) {
		size_t lenCorrection = 0;

		for (size_t j = jacobs[i]; j > jacobs[i - 1]; j--) {
			size_t insertedIdx = insertVec(pairsSet[0], j + insertedCnt - lenCorrection, pairsSet[1][j]);
			for (size_t k = 2; k < pairsSet.size(); k += 2) {
				pairsSet[k].insert(pairsSet[k].begin() + insertedIdx, pairsSet[k + 1][j]);
			}

			if (insertedIdx >= j + insertedCnt - lenCorrection)
				lenCorrection++;
			insertedCnt++;
		}
	}

	for (size_t i = 3; i < pairsSet.size(); i += 2) {
		for (size_t j = pairsSet[1].size(); j < pairsSet[i].size(); j++) {
			pairsSet[i - 1].push_back(pairsSet[i][j]);
		}
	}

	for (size_t i = 0; i < pairsSet.size(); i += 2) {
		newSet->push_back(pairsSet[i]);
	}

	delete &pairsSet;

	if (newSet->size() == 1) {
		return newSet;
	}

	return mergeVec(*newSet);
}

template <class T>
std::vector<T> pmergeMeVec(std::vector<T> &v) {
	std::vector<std::vector<T> > *pairsSet = new std::vector<std::vector<T> >;

	pairsSet->push_back(v);
	pairsSet = divideVec(*pairsSet, 0);
	pairsSet = mergeVec(*pairsSet);

	std::vector<T> res = (*pairsSet)[0];
	delete pairsSet;
	return (res);
}

template <class T>
std::deque<std::deque<T> >* divideDeq(std::deque<std::deque<T> > &pairsSet, int depth) {
	std::deque<std::deque<T> >* newSet = new std::deque<std::deque<T> >;

	newSet->resize(std::pow(2, (depth + 1)));

	for (size_t i = 0; i + 1 < pairsSet[0].size(); i += 2) {
		if (pairsSet[0][i] < pairsSet[0][i + 1]) {
			for (size_t j = 0; j < pairsSet.size(); j++) {
				(*newSet)[j * 2].push_back(pairsSet[j][i + 1]);
				(*newSet)[j * 2 + 1].push_back(pairsSet[j][i]);
			}
		} else {
			for (size_t j = 0; j < pairsSet.size(); j++) {
				(*newSet)[j * 2].push_back(pairsSet[j][i]);
				(*newSet)[j * 2 + 1].push_back(pairsSet[j][i + 1]);
			}
		}
	}

	size_t remainder = (pairsSet[0].size() / 2) * 2;
	for (size_t i = 0; i < pairsSet.size(); i++) {
		for (unsigned int j = remainder; j < pairsSet[i].size(); j++) {
			(*newSet)[i * 2 + 1].push_back(pairsSet[i][j]);
		}
	}
	delete &pairsSet;

	if ((*newSet)[0].size() < 3) {
		if ((*newSet)[0].size() == 2 && (*newSet)[0][0] > (*newSet)[0][1]) {
			T tmp;
			for (size_t i = 0; i < newSet->size(); i++) {
				tmp = (*newSet)[i][0];
				(*newSet)[i][0] = (*newSet)[i][1];
				(*newSet)[i][1] = tmp;
			}
		}

		return (newSet);
	}

	return divideDeq(*newSet, depth + 1);
}

template <class T>
size_t insertDeq(std::deque<T> &v, size_t upperBound, T value) {
	ssize_t l = -1;
	ssize_t r = upperBound;

	while (l + 1 < r) {
		ssize_t m = (l + r) / 2;

		if (v[m] >= value) {
			r = m;
		} else {
			l = m;
		}
	}

	v.insert(v.begin() + r, value);
	return r;
}

template <class T>
std::deque<std::deque<T> >* mergeDeq(std::deque<std::deque<T> > &pairsSet) {
	std::deque<std::deque<T> >* newSet = new std::deque<std::deque<T> >;
		size_t insertedCnt = 1;

	for (size_t i = 0; i + 1 < pairsSet.size(); i += 2) {
		pairsSet[i].insert(pairsSet[i].begin(), pairsSet[i + 1][0]);
	}

	std::deque<size_t> jacobs;
	for (size_t i = 1; ; i++) {
		size_t j = jacob(i);
		if (j < pairsSet[1].size()) {
			jacobs.push_back(j - 1);
		} else {
			jacobs.push_back(pairsSet[1].size() - 1);
			break;
		}
	}

	for (size_t i = 1; i < jacobs.size(); i++) {
		size_t lenCorrection = 0;

		for (size_t j = jacobs[i]; j > jacobs[i - 1]; j--) {
			size_t insertedIdx = insertDeq(pairsSet[0], j + insertedCnt - lenCorrection, pairsSet[1][j]);
			for (size_t k = 2; k < pairsSet.size(); k += 2) {
				pairsSet[k].insert(pairsSet[k].begin() + insertedIdx, pairsSet[k + 1][j]);
			}

			if (insertedIdx >= j + insertedCnt - lenCorrection)
				lenCorrection++;
			insertedCnt++;
		}
	}

	for (size_t i = 3; i < pairsSet.size(); i += 2) {
		for (size_t j = pairsSet[1].size(); j < pairsSet[i].size(); j++) {
			pairsSet[i - 1].push_back(pairsSet[i][j]);
		}
	}

	for (size_t i = 0; i < pairsSet.size(); i += 2) {
		newSet->push_back(pairsSet[i]);
	}

	delete &pairsSet;

	if (newSet->size() == 1) {
		return newSet;
	}

	return mergeDeq(*newSet);
}

template <class T>
std::deque<T> pmergeMeDeq(std::deque<T> &v) {
	std::deque<std::deque<T> > *pairsSet = new std::deque<std::deque<T> >;

	pairsSet->push_back(v);
	pairsSet = divideDeq(*pairsSet, 0);
	pairsSet = mergeDeq(*pairsSet);

	std::deque<T> res = (*pairsSet)[0];
	delete pairsSet;
	return (res);
}

#endif
