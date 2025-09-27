/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:04:39 by miparis           #+#    #+#             */
/*   Updated: 2025/09/27 18:47:21 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#ifndef HUMAN_B
#define HUMAN_B

class HumanB
{
	public:
	void	attack();
	void	setWeapon(Weapon weapon); //here it has to receive a weapon object already created
	HumanB(std::string name)
	{
		this->name = name;
	}

	private:
	std::string	name;
	Weapon weapon;
};

#endif