/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 22:03:21 by miparis           #+#    #+#             */
/*   Updated: 2026/02/12 23:12:28 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"

Brain:: Brain()
{
	std::cout << PURPLE << "(Def.) " << "Ideas ideas ideas ..." << NC << std::endl;
}

Brain::Brain(const Brain& _copy)
{
	*this = _copy;
	std::cout << PURPLE << "(Copy) " << "Ideas ideas ideas ..." << NC << std::endl;
}

Brain& Brain::operator=(const Brain& _copy)
{
	if (this != &_copy)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = _copy.ideas[i];
	}
	std::cout << PURPLE << "(Assign op.) " << "Ideas ideas ideas ..." << NC << std::endl;
	return (*this);
}

Brain:: ~Brain()
{
	std::cout << RED << "(Destruct.) " << " < Brain in invernation >" << NC << std::endl;
}