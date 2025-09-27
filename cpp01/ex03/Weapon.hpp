/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:04:32 by miparis           #+#    #+#             */
/*   Updated: 2025/09/20 19:09:21 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON
#define WEAPON

#include <iostream>
#include <iomanip>
#include <string>

typedef Weapon
{
	public:
	const std::string& getType();
	void setType(std::string new_value);

	private:
	std::string type;
};
#endif