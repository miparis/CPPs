/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:54:29 by miparis           #+#    #+#             */
/*   Updated: 2026/08/05 12:33:04 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//int main()
//{
//	Span sp = Span(5);
//	sp.addNumber(6);
//	sp.addNumber(3);
//	sp.addNumber(17);
//	sp.addNumber(9);
//	sp.addNumber(11);
//	std::cout << sp.shortestSpan() << std::endl;
//	std::cout << sp.longestSpan() << std::endl;
//	return 0;
//}

int main()
{
    //Test to check with the 10.000 values as the subjects asks
    
    Span masiveSpan(10000); //Vector with 10.000 capacity

	//here we create a vector and fill it up randomly
    std::vector<int> randomNumbers;
    srand(time(NULL));
    for (int i = 0; i < 10000; i++)
        randomNumbers.push_back(rand());

    try 
    {
        masiveSpan.addNumbers(randomNumbers.begin(), randomNumbers.end());
        std::cout << BLUE << "10,000 added correctly" << NC << std::endl;

        std::cout << "Shortest Span: " << masiveSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << masiveSpan.longestSpan() << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error adding values" << std::endl;
    }

    return 0;
}