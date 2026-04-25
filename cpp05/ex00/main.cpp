/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:19:05 by miparis           #+#    #+#             */
/*   Updated: 2026/04/25 17:39:29 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	// Test 1: El Burócrata Perfecto
	std::cout << "--- Test 1: Normal ---" << std::endl;
	try {
		Bureaucrat b1("Hermes Conrad", 42);
		std::cout << b1;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	// Test 2: El que se cree demasiado bueno (Grade too High)
	std::cout << "\n--- Test 2: Constructor Too High ---" << std::endl;
	try {
		Bureaucrat b2("God", 0); 
		std::cout << b2;
	} catch (std::exception &e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	// Test 3: El becario (Grade too Low)
	std::cout << "\n--- Test 3: Constructor Too Low ---" << std::endl;
	try {
		Bureaucrat b3("Intern", 151);
		std::cout << b3;
	} catch (std::exception &e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	// Test 4: Forzando el ascenso al límite
	std::cout << "\n--- Test 4: Increment at Limit ---" << std::endl;
	try {
		Bureaucrat b4("High Rank", 2);
		std::cout << b4;
		b4.incrementGrade(1); // Pasa a 1
		std::cout << b4;
		b4.incrementGrade(1); // Debería lanzar excepción (0 no existe)
	} catch (std::exception &e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}
	return (0);
}
