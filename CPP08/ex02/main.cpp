#include "Mutantstack.hpp"
#include <iostream>
#include <list>

void processList()
{
	std::list<int> l;
	l.push_back(1);
	l.push_back(2);
	std::cout << l.back() << std::endl;
	l.pop_back();
	std::cout << l.size() << std::endl;
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);
	std::list<int>::iterator it = l.begin();
	std::list<int>::iterator ite = l.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		std::cout << "--------------------------------" << std::endl;
		++it;
	}
}

int main()
{
	std::cout << "List:" << std::endl;
	processList();
	std::cout << "MutantStack:" << std::endl;
	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	mstack.push(6);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		std::cout << "--------------------------------" << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

