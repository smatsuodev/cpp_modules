#include "MutantStack.hpp"
#include <vector>
#include <iostream>
#include <stack>
#include <list>
#include <cassert>

int main() {
	{
		std::cout << "------ Test in subject ------" << std::endl;

		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);

		std::cout << "-----------------------------" << std::endl;
	}
	{
		MutantStack<int> stack;
		std::list<int> list;

		stack.push(5);
		list.push_back(5);
		assert(stack.top() == list.back());
		assert(stack.size() == list.size());
		stack.push(17);
		list.push_back(17);
		assert(stack.top() == list.back());
		assert(stack.size() == list.size());

		stack.pop();
		list.pop_back();

		assert(stack.top() == list.back());
		assert(stack.size() == list.size());

		stack.push(3);
		list.push_back(3);
		assert(stack.top() == list.back());
		assert(stack.size() == list.size());
		stack.push(5);
		list.push_back(5);
		assert(stack.top() == list.back());
		assert(stack.size() == list.size());
		stack.push(737);
		list.push_back(737);
		assert(stack.top() == list.back());
		assert(stack.size() == list.size());
		stack.push(0);
		list.push_back(0);
		assert(stack.top() == list.back());
		assert(stack.size() == list.size());

		MutantStack<int>::iterator itStack = stack.begin();
		MutantStack<int>::iterator iteStack = stack.end();
		std::list<int>::iterator itList = list.begin();
		std::list<int>::iterator iteList = list.end();

		while (itStack != iteStack) {
			assert(*itStack == *itList);
			++itStack;
			++itList;
		}
		assert(itList == iteList);

		std::cout << "Test same as list passed" << std::endl;
	}
	{
		MutantStack<int, std::vector<int> > mutantStack;
		std::stack<int, std::vector<int> > stack;

		mutantStack.push(5);
		stack.push(5);
		assert(mutantStack.top() == stack.top());
		assert(mutantStack.size() == stack.size());
		mutantStack.push(17);
		stack.push(17);
		assert(mutantStack.top() == stack.top());
		assert(mutantStack.size() == stack.size());

		mutantStack.pop();
		stack.pop();
		assert(mutantStack.top() == stack.top());
		assert(mutantStack.size() == stack.size());

		mutantStack.push(3);
		stack.push(3);
		assert(mutantStack.top() == stack.top());
		assert(mutantStack.size() == stack.size());
		mutantStack.push(5);
		stack.push(5);
		assert(mutantStack.top() == stack.top());
		assert(mutantStack.size() == stack.size());
		mutantStack.push(737);
		stack.push(737);
		assert(mutantStack.top() == stack.top());
		assert(mutantStack.size() == stack.size());
		mutantStack.push(0);
		stack.push(0);
		assert(mutantStack.top() == stack.top());
		assert(mutantStack.size() == stack.size());

		std::cout << "Test same as stack_ passed" << std::endl;
	}
	{
		MutantStack<int> stack;
		assert(stack.size() == 0);
		assert(stack.empty());
		stack.push(42);
		assert(stack.size() == 1);
		assert(!stack.empty());
		stack.pop();
		assert(stack.size() == 0);
		assert(stack.empty());

		std::cout << "Test empty passed" << std::endl;
	}
	return 0;
}
