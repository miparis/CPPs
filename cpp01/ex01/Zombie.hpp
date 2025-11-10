/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:27:50 by miparis           #+#    #+#             */
/*   Updated: 2025/11/10 10:59:00 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_H
#define ZOMBIE_H

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

class Zombie
{
	public:
	void	announce( void );
	Zombie();
	Zombie(std::string name);

	private:
	std::string	name;
};

Zombie* zombieHorde( int N, std::string name );

#endif