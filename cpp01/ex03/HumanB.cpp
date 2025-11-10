/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:04:41 by miparis           #+#    #+#             */
/*   Updated: 2025/11/10 11:35:48 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack()
{
	if (weapon)
		std::cout << BOLD << BLUE << this->name << " attacks with their " <<  weapon->getType() << NC << std::endl;
	else
		std::cout << BOLD << RED << this->name << " tries to attack, but he doesn't have a weapon X0" <<  NC << std::endl;
}
void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}