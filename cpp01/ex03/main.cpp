/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:00:38 by miparis           #+#    #+#             */
/*   Updated: 2025/10/18 18:45:49 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		//Test for humanB trying to attack with no weapon
		HumanB sand("Sand");
		sand.attack();
	}
	{
		//Trying to attack with weapon not initialize with any type setted, hence it takes the default
		Weapon noWeapon;
		HumanB marlon("Marlon");
		marlon.setWeapon(noWeapon);
		marlon.attack();
	}
	return 0;
}