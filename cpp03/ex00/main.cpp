/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:17:19 by miparis           #+#    #+#             */
/*   Updated: 2026/01/29 09:39:00 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::cout << "--- Create ---" << std::endl;
	ClapTrap _mario("_mario");
	ClapTrap _warrio("_warrio");
	_mario.status();
	_warrio.status();

	std::cout << "---  Use all energy ---" << std::endl;
	for (int i = 0; i < 10; i++)
		_mario.attack("a Goomba");
	_mario.status();

	std::cout << "--- Failed actions ---" << std::endl;
	_mario.attack("a Goomba");
	_mario.beRepaired(5);
	_mario.status();

	std::cout << "--- Dead because of points ---" << std::endl;
	_warrio.status();
	_warrio.takeDamage(10);
	_warrio.status();

	std::cout << "--- Post-mortem ---" << std::endl;
	_warrio.attack("_mario");
	_warrio.beRepaired(10);
	_warrio.status();

	return 0;
}