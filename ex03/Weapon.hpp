/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:04:32 by miparis           #+#    #+#             */
/*   Updated: 2025/10/18 18:33:22 by miparis          ###   ########.fr       */
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
	Weapon();
	Weapon(std::string weapon);
	const std::string& getType() const;
	void setType(std::string new_value);

	private:
	std::string type;
};
#endif