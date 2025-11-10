/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:03:16 by miparis           #+#    #+#             */
/*   Updated: 2025/11/10 10:52:00 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << BOLD << BLUE << "<---- Testing default zombie ---->" << NC << std::endl;
	Zombie	normy("Normy");
	normy.announce();

	std::cout << BOLD << GREEN << "<---- Testing stacky zombie ---->" << NC << std::endl;
	randomChump("Stacky");

	std::cout << BOLD << RED << "<---- Testing heapy zombie ---->" << NC << std::endl;
	Zombie	*heapy;
	heapy = newZombie("Heapy");
	heapy->announce();

	std::cout << BOLD << RED << "<---- Deleting heapy zombie... ---->" << NC << std::endl;
	delete heapy;

	return (0);
}