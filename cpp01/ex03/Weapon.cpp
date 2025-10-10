/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:04:35 by miparis           #+#    #+#             */
/*   Updated: 2025/10/10 17:47:59 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(): type("default") {
	std::cout << "Default weapong constructor called" << std::endl;
}

Weapon::Weapon(std::string const weapon)
{
	std::cout << "Assignation weapon constructor called" << std::endl;
	if (weapon.empty())
		this->type = "Default";
	else
		this->type = weapon;
}
const std::string& Weapon::getType() const
{
	return (this->type);
}

void Weapon::setType(std::string new_value)
{
	this->type = new_value;
}