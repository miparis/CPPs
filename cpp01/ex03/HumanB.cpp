/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:04:41 by miparis           #+#    #+#             */
/*   Updated: 2025/10/18 18:37:30 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack()
{
	if (weapon)
		std::cout << this->name << " attacks with their " <<  weapon->getType() << std::endl;
	else
		std::cout << this->name << " tries to attack, but he doesn't have a weapon X0" <<  std::endl;
}
void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}