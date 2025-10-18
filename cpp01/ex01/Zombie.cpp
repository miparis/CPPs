/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:40:22 by miparis           #+#    #+#             */
/*   Updated: 2025/09/13 20:41:33 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie:: Zombie()
{
	this->name = "Def";
}
Zombie:: Zombie(std::string name)
{
	this->name = name;
}
void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}