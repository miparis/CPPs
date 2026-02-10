/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:17:19 by miparis           #+#    #+#             */
/*   Updated: 2026/02/10 18:53:50 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::cout << GREEN << "--- Orthodox Canonical Form ---" << NC << std::endl;
	std::cout << "--- Testing Default Constructor ---" << std::endl;
	ClapTrap defaultBot;
	//defaultBot.status();

	std::cout << "\n--- Testing Parameterized Constructor ---" << std::endl;
	ClapTrap clappy("Clappy");
	//clappy.status();

	std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
	ClapTrap clone(clappy);
	//clone.status();

	std::cout << "\n--- Testing Copy Assignment Operator ---" << std::endl;
	defaultBot = clappy;
	//defaultBot.status();

	std::cout << GREEN << "--- Methods ---" << NC << std::endl;
	ClapTrap _clapper("_Clappy");

	_clapper.attack("Target A");
	_clapper.takeDamage(5);
	_clapper.beRepaired(3);

	for (int i = 0; i < 10; i++)
	{
		_clapper.attack("Target B");
		_clapper.status();
	}

	_clapper.beRepaired(5);
	_clapper.status();
	_clapper.takeDamage(20);
	_clapper.status();
	_clapper.attack("Targe C");

	return (0);
}

