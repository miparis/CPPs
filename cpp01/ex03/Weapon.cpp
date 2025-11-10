/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:04:35 by miparis           #+#    #+#             */
/*   Updated: 2025/10/18 18:37:53 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(): type("Default") {
}

Weapon::Weapon(std::string const weapon)
{
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