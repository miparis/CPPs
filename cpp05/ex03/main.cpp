/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:19:05 by miparis           #+#    #+#             */
/*   Updated: 2026/06/04 12:02:12 by miparis          ###   ########.fr       */
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
		Bureaucrat	_boss("The boss", 1);
		AForm*	_rrf;

		_rrf = _randomIntern.makeForm("robotomy request", "Bender");
		if (_rrf != NULL)
		{
			std::cout << BLUE << *_rrf; //check initial state

			_boss.signForm(*_rrf);
			_boss.executeForm(*_rrf);

			std::cout << BLUE << *_rrf; //check final state

			delete (_rrf); //to avoid leaks
		}
	}

	std::cout << YELLOW << "\n--- Test 2: Invalid creation---" << NC << std::endl;
	{
		Intern	_randomIntern;
		Bureaucrat	_boss("The boss", 1);
		AForm*	_rrf;

		_rrf = _randomIntern.makeForm("vacation request?", "Bender");
		
		//here the correspondign error message from makeForm should appear
		
		delete (_rrf);
	}

	return 0;
}
