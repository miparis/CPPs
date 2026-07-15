/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:03:25 by miparis           #+#    #+#             */
/*   Updated: 2026/07/15 13:20:03 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <vector>
#include <deque>

int main()
{
	std::cout << BLUE << "------------ 1st test: List ---------------" << NC << std::endl;
	int _arr[] = {5, 4, 3, 2, 1};
	size_t _size = sizeof(_arr) / sizeof(_arr[0]);
	std::list<int> _myArr(_arr, _arr + _size);

	try 
	{
		std::list<int> ::iterator _it = ::easyfind(_myArr, 2);
		std::cout << GREEN << "First ocurrence found: " << *_it << NC << std::endl;
	} 
	catch (const std::exception& e) 
	{
		std::cerr << RED << "Error: Ocurrence not found" << NC << std::endl;
	}
	
	std::cout << BLUE << "------------ 2nd test: Empty list ---------------" << NC << std::endl;
	int _arr2[] = {};
	size_t _size2 = sizeof(_arr2) / sizeof(_arr2[0]);
	std::list<int> _myEList(_arr2, _arr2 + _size2);

	try 
	{
		std::list<int>::iterator _it = ::easyfind(_myEList, 10);
		std::cout << GREEN << "First ocurrence found: " << *_it << NC << std::endl;
	} 
	catch (const std::exception& e) 
	{
		std::cerr << RED << "Error: Ocurrence not found" << NC << std::endl;
	}

	std::cout << BLUE << "------------ 3rd test: Vector ---------------" << NC << std::endl;
	int _arr3[] = {59, 59, 0, -40, 42, 36, 56};
	size_t _size3 = sizeof(_arr3) / sizeof(_arr3[0]);
	std::vector<int> _myVector(_arr3, _arr3 + _size3);

	try 
	{
		std::vector<int>::iterator _it = ::easyfind(_myVector, 59);
		std::cout << GREEN << "First ocurrence found: " << *_it << NC << std::endl;
	} 
	catch (const std::exception& e) 
	{
		std::cerr << RED << "Error: Ocurrence not found" << NC << std::endl;
	}

	std::cout << BLUE << "------------ 4th test: Deque ---------------" << NC << std::endl;
	int _arr4[] = {59, 59, 0, -40, 42, 36, 56};
	size_t _size4 = sizeof(_arr4) / sizeof(_arr4[0]);
	std::deque<int> _myDeq(_arr4, _arr4 + _size4);

	try 
	{
		std::deque<int>::iterator _it = ::easyfind(_myDeq, 5);
		std::cout << GREEN << "First ocurrence found: " << *_it << NC << std::endl;
	} 
	catch (const std::exception& e) 
	{
		std::cerr << RED << "Error: Ocurrence not found" << NC << std::endl;
	}

	return (0);
}