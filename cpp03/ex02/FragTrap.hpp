/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:06:48 by miparis           #+#    #+#             */
/*   Updated: 2026/02/10 18:51:18 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& _copy);
	FragTrap& operator=(const FragTrap& _copy);
	~FragTrap(void);
	
	void highFivesGuys(void);
	//void attack(const std::string& target); -> FragTrap should use the method inherated from ClapTrap
};

#endif