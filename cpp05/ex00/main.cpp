/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:19:05 by miparis           #+#    #+#             */
/*   Updated: 2026/05/26 11:42:21 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	/* 							PERFECT BUREAUCRAT						*/	
	std::cout << "--- Test 1: Normal ---" << std::endl;
	try {
		Bureaucrat b1("Hermes Conrad", 42);
		std::cout << b1;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	/* 							GRADE TOO HIGH FOR BREAUCRAT			 */	
	std::cout << "\n--- Test 2: Constructor Too High ---" << std::endl;
	try {
		Bureaucrat b2("God", 0); 
		std::cout << b2;
	} catch (std::exception &e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	/* 							GRADE TOO LOW FOR BREAUCRAT			 */	
	std::cout << "\n--- Test 3: Constructor Too Low ---" << std::endl;
	try {
		Bureaucrat b3("Intern", 151);
		std::cout << b3;
	} catch (std::exception &e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	/*				INCREASING GRADE BREAUCRAT						*/
	std::cout << "\n--- Test 4: Increment at Limit ---" << std::endl;
	try {
		Bureaucrat b4("High Rank", 2);
		std::cout << b4;
		b4.incrementGrade(1); // to 1
		std::cout << b4;
		b4.incrementGrade(1); // Exception (0 doesnt exist)
	} catch (std::exception &e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}
	return (0);
}
