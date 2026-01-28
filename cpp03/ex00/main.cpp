/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:17:19 by miparis           #+#    #+#             */
/*   Updated: 2026/01/28 17:32:05 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::cout << "--- Create ---" << std::endl;
	ClapTrap mario("Mario");
	ClapTrap warrio("Warrio");
	mario.status();
	warrio.status();

	std::cout << "---  Use all energy ---" << std::endl;
	for (int i = 0; i < 10; i++)
		mario.attack("a Goomba");
	mario.status();

	std::cout << "--- Failed actions ---" << std::endl;
	mario.attack("a Goomba");
	mario.beRepaired(5);
	mario.status();

	std::cout << "--- Dead because of points ---" << std::endl;
	warrio.status();
	warrio.takeDamage(10);
	warrio.status();

	std::cout << "--- Post-mortem ---" << std::endl;
	warrio.attack("Mario");
	warrio.beRepaired(10);
	warrio.status();

	return 0;
}