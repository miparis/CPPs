/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:03:26 by miparis           #+#    #+#             */
/*   Updated: 2025/09/13 19:03:58 by miparis          ###   ########.fr       */
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
	Zombie(std::string name);
	~Zombie();

	private:
	std::string	name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif