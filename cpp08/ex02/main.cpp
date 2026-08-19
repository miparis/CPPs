/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 13:03:24 by miparis           #+#    #+#             */
/*   Updated: 2026/08/19 12:16:17 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << BLUE << "----- Test with Mutant Stack ------ " << NC << std::endl;
	
	MutantStack<int>  mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top value = " << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << "Size = "<< mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	MutantStack<int>::_iterator it = mstack.begin();
	MutantStack<int>::_iterator ite = mstack.end();
	
	++it;
	--it;

	std::cout << "Values of stack: " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << BLUE << "----- Test with list ------ " << NC << std::endl;
	
	std::list<int>	mlist;
	
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << "Top value = " << mlist.back() << std::endl;

	mlist.pop_back();
	
	std::cout << "Size = "<< mlist.size() << std::endl;
	
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);

	std::list<int>::iterator it2 = mlist.begin();
	std::list<int>::iterator ite3 = mlist.end();
	++it;
	--it;
	std::cout << "Values of list: " << std::endl;
	while (it2 != ite3)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}

	std::cout << BLUE << "----- Test with vector ------ " << NC << std::endl;
	
	std::vector<int>	mvector;
	
	mvector.push_back(5);
	mvector.push_back(17);
	std::cout << "Top value = "<< mvector.back() << std::endl;

	mvector.pop_back();
	
	std::cout << "Size = "<< mvector.size() << std::endl;
	
	mvector.push_back(3);
	mvector.push_back(5);
	mvector.push_back(737);
	mvector.push_back(0);

	std::vector<int>::iterator it4 = mvector.begin();
	std::vector<int>::iterator ite5 = mvector.end();
	++it;
	--it;
	std::cout << "Values of vector: " << std::endl;
	while (it4 != ite5)
	{
		std::cout << *it4 << std::endl;
		++it4;
	}

	return 0;
}