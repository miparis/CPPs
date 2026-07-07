/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 12:54:23 by miparis           #+#    #+#             */
/*   Updated: 2026/07/07 16:38:50 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	/*
	Syntaxis for declaration using the Array template
	Array<datatype> name; -> default const
	Array<datatype> name(size); -> aplying a size
	*/
	std::cout << BLUE << "------------ 1st test: Empty template ---------------" << NC << std::endl;
	Array<int> A;
	unsigned int aSize = A.size();
	std::cout << GREEN << "Array size = " <<  aSize << NC << std::endl;
	for (unsigned int i = 0; i < aSize; i++)
		std::cout << YELLOW << "Index = " << i << "Value = " << A[i] << NC << std::endl;
	std::cout << BLUE << "------------ 2nd test: Trying the overflow exception -----------" << NC << std::endl;
	try 
	{
		std::cout << YELLOW << "Size = " << aSize << std::endl << "Index to try = " << 4 << NC << std::endl;
		std::cout << RED << "Result = " << A[4] << NC << std::endl;
	}
	catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << BLUE << "------------ 3rd test: Assigment template ---------------" << NC << std::endl;
	Array<int> B(42);
	unsigned int bSize = B.size();
	for (unsigned int i = 0; i < bSize; i++)
    {
        B[i] = i * 10; 
    }
	std::cout << GREEN << "________ Values of array __________" << NC << std::endl;
	for (unsigned int i = 0; i < bSize; i++)
		std::cout << "Index = " << i << "______Value = " << B[i] << std::endl;
	std::cout << BLUE << "------------ Trying the overflow exception (again) -----------" << NC << std::endl;
	try 
	{

		std::cout << YELLOW << "Trying index " << bSize + 1 << NC << std::endl;
		std::cout << RED << "Result = " << B[bSize + 1] << NC << std::endl;
	}
	catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << BLUE << "------------ 4th test: Assigment template ---------------" << NC << std::endl;
	Array<std::string> C(4);
	unsigned int cSize = C.size();
	for (unsigned int i = 0; i < cSize; i++)
    {
        C[i] = "Miranda";
    }
	std::cout << GREEN << "________ Values of array __________" << NC << std::endl;
	for (unsigned int i = 0; i < cSize; i++)
		std::cout << "Index = " << i << "______Value = " << C[i] << std::endl;
	std::cout << BLUE << "------------ 5th test: Deep copy ---------------" << NC << std::endl;
	Array<int> D(4);
	unsigned int dSize = D.size();
	for (unsigned int i = 0; i < dSize; i++)
    {
        D[i] = i * 2; 
    }
	Array<int> E = D;
	unsigned int eSize = E.size();
	std::cout << GREEN << "________ Values of D array __________" << NC << std::endl;
	for (unsigned int i = 0; i < dSize; i++)
		std::cout << "Index = " << i << "______Value = " << D[i] << std::endl;
	std::cout << GREEN << "________ Values of E array __________" << NC << std::endl;
	for (unsigned int i = 0; i < eSize; i++)
		std::cout << "Index = " << i << "______Value = " << E[i] << std::endl;
	return (0);
}