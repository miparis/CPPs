/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:03:16 by miparis           #+#    #+#             */
/*   Updated: 2025/09/13 18:58:24 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << "<---- Testing default zombie ---->" << std::endl;
	Zombie	normy("Normy");
	normy.announce();

	std::cout << "<---- Testing stacky zombie ---->" << std::endl;
	randomChump("Stacky");

	std::cout << "<---- Testing heapy zombie ---->" << std::endl;
	Zombie	*heapy;
	heapy = newZombie("Heapy");
	heapy->announce();

	std::cout << "<---- Deleting heapy zombie... ---->" << std::endl;
	delete heapy;

	return (0);
}