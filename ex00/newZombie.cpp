/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:15:01 by miparis           #+#    #+#             */
/*   Updated: 2025/09/13 18:46:58 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//Here we create a zombie in the heap accesible for other places
Zombie* newZombie( std::string name )
{
	Zombie	*zombieCreated;

	zombieCreated = new Zombie(name);
	
	return (zombieCreated);
}