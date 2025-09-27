/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:04:44 by miparis           #+#    #+#             */
/*   Updated: 2025/09/27 18:35:42 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#ifndef HUMAN_A
#define HUMAN_A

class HumanA
{
	public:
	void	attack();
	HumanA(std::string name, std::string weapon)
	{
		this->name = name;
		this->weapon.setType(weapon);
	}

	private:
	std::string	name;
	Weapon weapon;
};

#endif