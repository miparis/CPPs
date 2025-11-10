/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:14:38 by miparis           #+#    #+#             */
/*   Updated: 2025/11/10 10:55:23 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie:: Zombie(std::string name)
{
	this->name = name;
}
void Zombie::announce( void )
{
	std::cout << BOLD << PURPLE << name << ": BraiiiiiiinnnzzzZ..." << NC << std::endl;
}

Zombie:: ~Zombie()
{
	std::cout << BOLD << YELLOW << name << " has finally died" << NC << std::endl;
}