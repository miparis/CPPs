/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:04:39 by miparis           #+#    #+#             */
/*   Updated: 2025/10/18 18:46:55 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B

#include "Weapon.hpp"

class HumanB
{
	public:
	HumanB(std::string name) //This type of constructor assign after constructor
	{
		this->name = name;
		this->weapon = NULL; //Weapon for HumanB can be empty when created the object, so me init it with NULL until setting
	}
	void	setWeapon(Weapon &weapon); //here it has to receive a weapon object already created
	void	attack();
	private:
	std::string	name;
	Weapon *weapon;
};

#endif<