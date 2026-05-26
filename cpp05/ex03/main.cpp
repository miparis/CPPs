/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:19:05 by miparis           #+#    #+#             */
/*   Updated: 2026/05/26 12:37:51 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
	std::srand(std::time(NULL)); //-> for rand() in robotomy

	/*							SUCCESS TEST								*/
	std::cout << BLUE << "\n--- Test 1: Intern creates a valid form ---" << NC << std::endl;
	{
		Intern	_randomIntern;
		Bureaucrat	boss("The boss", 1);
		AForm*	rrf;

		rrf = _randomIntern.makeForm("robotomy request", "Bender");
		if (rrf != NULL)
		{
			std::cout << BLUE << *rrf; //check initial state

			boss.signForm(*rrf);
			boss.executeForm(*rrf);

			std::cout << BLUE << *rrf; //check final state

			delete rrf; //to avoid leaks
		}
	}

	std::cout << YELLOW << "\n--- Test 2: Invalid creation---" << NC << std::endl;
	{
		Intern	_randomIntern;
		Bureaucrat	boss("The boss", 1);
		AForm*	rrf;

		rrf = _randomIntern.makeForm("vacation request?", "Bender");
		
		//here the correspondign error message from makeForm should appear
		
		delete rrf;
	}

	return 0;
}
