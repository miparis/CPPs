/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:17:19 by miparis           #+#    #+#             */
/*   Updated: 2026/02/01 18:40:14 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
   std::cout << GREEN << "--- Orthodox Canonical Form ---" << NC << std::endl;
	std::cout << "--- Testing Default Constructor ---" << std::endl;
	ScavTrap defaultBot;
	defaultBot.status();

	std::cout << "\n--- Testing Parameterized Constructor ---" << std::endl;
	ScavTrap scavy("Scavy");
	scavy.status();

	std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
	ScavTrap clone(scavy);
	clone.status();

	std::cout << "\n--- Testing Copy Assignment Operator ---" << std::endl;
	defaultBot = scavy;
	defaultBot.status();

	std::cout << GREEN << "--- Methods ---" << NC << std::endl;
	ScavTrap _scavy("_Scavy");

    _scavy.attack("an intruder");
    _scavy.takeDamage(50);
    _scavy.beRepaired(20);
    _scavy.guardGate();

    return (0);
}