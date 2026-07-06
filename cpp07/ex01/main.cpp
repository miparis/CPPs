/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:24:19 by miparis           #+#    #+#             */
/*   Updated: 2026/07/06 12:59:10 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void printElement(const T& element)
{
    std::cout << PURPLE << element << " " << NC << std::endl;;
}

void addOne(int& number)
{
    number += 1;
}

int main()
{
	std::cout << BLUE << "------------ First test: char array  ---------------" << NC << std::endl;
	const char cArray[] = "Miranda";
	size_t arrayLength = sizeof(cArray) / sizeof(cArray[0]);
	std::cout << GREEN << "Array = " << cArray << std::endl << "Size = " << arrayLength << NC << std::endl;
	std::cout << YELLOW << "... Applying iter ..." << NC << std::endl;
	::iter(cArray, arrayLength, printElement<char>);

	std::cout << BLUE << "------------ Second test: string array  ---------------" << NC << std::endl;
	const std::string sArray[] = {"Miranda", "has", "done", "this"};
	size_t arraySLength = sizeof(sArray) / sizeof(sArray[0]);
	std::cout << YELLOW << "... Applying iter ..." << NC << std::endl;
	::iter(sArray, arraySLength, printElement<std::string>);

	std::cout << BLUE << "------------ Thrid test: int array mutable  ---------------" << NC << std::endl;
	int iArray[] = {16, 45, 33, 432};
	size_t arrayILength = sizeof(iArray) / sizeof(iArray[0]);
	::iter(iArray, arrayILength, addOne);
	std::cout << GREEN << " Resulting Array = " <<  std::endl;
	::iter(iArray, arrayILength, printElement<int>);

	return (0);
}