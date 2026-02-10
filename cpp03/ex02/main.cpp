/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:17:19 by miparis           #+#    #+#             */
/*   Updated: 2026/02/10 18:52:50 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << GREEN << "--- Orthodox Canonical Form ---" << NC << std::endl;
	std::cout << "--- Testing Default Constructor ---" << std::endl;
	FragTrap defaultBot;
	//defaultBot.status();

	std::cout << "\n--- Testing Parameterized Constructor ---" << std::endl;
	FragTrap _frag("_frag");
	//_frag.status();

	std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
	FragTrap clone(_frag);
	//clone.status();

	std::cout << "\n--- Testing Copy Assignment Operator ---" << std::endl;
	defaultBot = _frag;
	//defaultBot.status();

	std::cout << GREEN << "--- Methods ---" << NC << std::endl;
	FragTrap _fraggy("fraggy");

	_fraggy.attack("a heavy enemy");
	_fraggy.takeDamage(30);
	_fraggy.beRepaired(30);
	_fraggy.highFivesGuys();

	return (0);
}