/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:04:32 by miparis           #+#    #+#             */
/*   Updated: 2025/11/10 11:34:54 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON
#define WEAPON

#include <iostream>
#include <iomanip>
#include <string>

const std::string GREEN  = "\033[0;32m"; // Bold Green
const std::string YELLOW = "\033[0;33m"; // Yellow
const std::string RED    = "\033[0;31m"; // Red
const std::string BLUE   = "\033[0;34m"; // Bold Blue
const std::string PURPLE = "\033[1;35m"; // Bold Purple
const std::string BOLD   = "\033[1m";    // Bold text
const std::string NC     = "\033[0m";    // Reset color

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