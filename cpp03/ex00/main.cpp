/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:17:19 by miparis           #+#    #+#             */
/*   Updated: 2026/01/28 09:48:41 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap _mario("_Mario");
	ClapTrap _warrio("_Warrio");

	std::cout << GREEN <<  "Battle begins!" << NC << std::endl;
	_mario.attack("_Warrio");
	_warrio.takeDamage(5);
	_warrio.beRepaired(2);
	_warrio.attack("_Mario");
	_mario.takeDamage(4);
}