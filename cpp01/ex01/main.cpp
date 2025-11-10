/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:49:11 by miparis           #+#    #+#             */
/*   Updated: 2025/11/10 11:10:43 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie	*horde;
	int		nbr = 4;
	std::string	name = "Charlezz";

	horde = zombieHorde(nbr, name);
	for (int i = 0; i < nbr; ++i)
	{
		std::cout << BLUE << "Zombi incoming [" << i + 1 << "]" << NC << std::endl;
		horde[i].announce();
	}
	std::cout << BOLD << RED << "< -- EVERYONE IS DEAD XO -->" << NC << std::endl;
	delete[] horde;
	horde = NULL;
	return (0);
}