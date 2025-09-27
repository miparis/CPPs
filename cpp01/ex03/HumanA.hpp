/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:04:44 by miparis           #+#    #+#             */
/*   Updated: 2025/09/27 19:39:31 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#ifndef HUMAN_A
#define HUMAN_A

class HumanA
{
	public:
	void	attack();
	HumanA(){};
	HumanA(std::string name, Weapon weapon)
	{
		this->name = name;
		this->weapon = weapon;
	}

	private:
	std::string	name;
	Weapon weapon;
};

#endif