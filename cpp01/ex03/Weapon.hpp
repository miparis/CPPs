/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:04:32 by miparis           #+#    #+#             */
/*   Updated: 2025/09/27 18:38:01 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON
#define WEAPON

#include <iostream>
#include <iomanip>
#include <string>

class Weapon
{
	public:
	Weapon(std::string weapon)
	{
		this->type = weapon;
	}
	Weapon(){};
	const std::string& Weapon::getType() const;
	void Weapon::setType(std::string new_value);

	private:
	std::string type;
};
#endif