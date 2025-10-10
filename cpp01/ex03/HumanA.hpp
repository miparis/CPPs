/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:04:44 by miparis           #+#    #+#             */
/*   Updated: 2025/10/10 17:51:36 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#ifndef HUMAN_A

class HumanA
{
	public:
	void	attack();
	HumanA(const std::string &name, Weapon &weapon)
        : name(name), weapon(weapon) {} //We assign at the moment of constructor, it cannot be empty
	private:
	std::string	name;
	Weapon &weapon;
};

#endif