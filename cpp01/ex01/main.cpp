/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:49:11 by miparis           #+#    #+#             */
/*   Updated: 2025/09/20 17:01:28 by miparis          ###   ########.fr       */
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
		std::cout << "Zombi incoming [" << i + 1 << "]" << std::endl;
		horde[i].announce();
	}
	std::cout << "< -- EVERYONE IS DEAD XO -->" << std::endl;
	delete[] horde;
	return (0);
}