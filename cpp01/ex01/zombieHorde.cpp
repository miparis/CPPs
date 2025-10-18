/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:40:34 by miparis           #+#    #+#             */
/*   Updated: 2025/09/13 20:41:12 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return NULL;

	Zombie	*horde = new Zombie[N];
	
	for (int i = 0; i < N; ++i)
		horde[i] = Zombie(name);
	return (horde);
}
