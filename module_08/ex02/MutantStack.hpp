#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <vector>
#include <deque>
#include <stack>

template<class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
	MutantStack() {}

	explicit MutantStack(const Container &cont) : std::stack<T, Container>(cont) {}

	MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {}

	~MutantStack() {}

	MutantStack &operator=(const MutantStack &other) {
		std::stack<T, Container>::operator=(other);
		return *this;
	}

	// Iterators
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;

	iterator begin() {
		return this->c.begin();
	};

	const_iterator begin() const {
		return this->c.begin();
	};

	iterator end() {
		return this->c.end();
	};

	const_iterator end() const {
		return this->c.end();
	};
};

#endif
