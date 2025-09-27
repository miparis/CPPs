/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:27:50 by miparis           #+#    #+#             */
/*   Updated: 2025/09/13 20:43:16 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <iomanip>
#include <string>

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