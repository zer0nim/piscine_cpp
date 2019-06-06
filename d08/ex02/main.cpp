#include "mutantstack.hpp"
#include "mutantstack.cpp"
#include <iostream>
#include <list>

int main(void)
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	std::cout << "_________" << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << std::endl;

	std::cout << "Same test with list _______________________" << std::endl;


	std::list<int> mstackList;

	mstackList.push_back(5);
	mstackList.push_back(17);

	std::cout << mstackList.back() << std::endl;

	mstackList.pop_back();

	std::cout << mstackList.size() << std::endl;

	mstackList.push_back(3);
	mstackList.push_back(5);
	mstackList.push_back(737);
	//[...]
	mstackList.push_back(0);

	std::cout << "_________" << std::endl;

	std::list<int>::iterator itList = mstackList.begin();
	std::list<int>::iterator iteList = mstackList.end();

	++itList;
	--itList;
	while (itList != iteList) {
		std::cout << *itList << std::endl;
		++itList;
	}
	std::list<int> sList(mstackList);

	return 0;
}
